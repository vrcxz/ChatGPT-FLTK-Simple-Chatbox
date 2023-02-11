#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json/json.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <fl/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include <windows.h> //only include when on windows

using namespace std;
using json = nlohmann::json;


string response_data;
string apiKey = "<add your api key here>";

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up) {
    for (int c = 0; c<size*nmemb; c++)
        response_data.push_back(buf[c]);
    return size*nmemb;
}

string generate_response(string prompt) {
    CURL* curl;
    CURLcode res;
    string gpt_output;

    response_data.clear();
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/engines/text-davinci-002/completions");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
        curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        
        headers = curl_slist_append(headers, ("Authorization: Bearer " + apiKey).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string postData = "{\"prompt\":\"" + prompt + "\",\"temperature\":0.5,\"max_tokens\":100,\"top_p\":1.0,\"frequency_penalty\":0,\"presence_penalty\":0}";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
            return "";
        } else {
            json response_json = json::parse(response_data);
            gpt_output = response_json["choices"][0]["text"].get<std::string>();
            return gpt_output;
        }
        curl_easy_cleanup(curl); 
        
        }
    return "";
}


void input_cb(Fl_Widget*, void* v) {
 
  Fl_Input *i = (Fl_Input*)v;
  string gpt_output = generate_response(i->value());
  string control_char = "\x0A";
  size_t pos = gpt_output.find(control_char);

    while (pos != std::string::npos) {
        gpt_output.erase(pos, control_char.length());
        pos = gpt_output.find(control_char);
    }


  Fl_Output *o = (Fl_Output*)(i->parent()->child(1));
  o->value(gpt_output.c_str());
}

int main(int argc, char **argv) {
  FreeConsole(); //remove console in windows
  string user_input;
  string gpt_output;
  Fl_Window *win = new Fl_Window(600, 600, "Simple ChatGPT API App");
  win->color(fl_rgb_color(40,40,40));

//resize (make sure you add your own resizing function, searching and debugging this is painful. FLTK apparently doesn't have it's own resize function.
Fl_PNG_Image *botimg;
botimg = new Fl_PNG_Image("whitebotsq.png");
Fl_Image *small_botimg = botimg->copy(50, 50);

Fl_Box box(120, 30, 10 ,10);
box.image(small_botimg);

Fl_Box *titletext = new Fl_Box(0, 30, 260, 100, "Prompt:");
 // titletext->box(FL_UP_BOX);
  titletext->labelsize(20);
  titletext->labelcolor(fl_rgb_color(250,250,250));
  //titletext->labeltype(FL_SHADOW_LABEL);


  Fl_Input *input = new Fl_Input(100, 99, 150, 30, "");
  input->box(FL_FLAT_BOX);
  input->textcolor(fl_rgb_color(250,250,250));
  input->color(fl_rgb_color(70,70,70));
  input->when(FL_WHEN_ENTER_KEY);
  input->callback(input_cb, input);

  Fl_Button buttonSubmit(260,100,50,30,"Enter");
  buttonSubmit.box(FL_FLAT_BOX);
  buttonSubmit.labelcolor(fl_rgb_color(250,250,250));
  buttonSubmit.color(fl_rgb_color(100,100,100));
  buttonSubmit.callback(input_cb, input);
  

  Fl_Output *output = new Fl_Output(100, 150, 400, 400, "");
 // output->align(FL_ALIGN_TOP);
  output->box(FL_FLAT_BOX);
  output->align(FL_ALIGN_LEFT_TOP);
  output->textcolor(fl_rgb_color(250,250,250));
  output->color(fl_rgb_color(70,70,70));
  output->wrap(1);

  win->add(buttonSubmit);  
  win->add(box);
  win->add(titletext);

  win->end();
  win->show(argc, argv);
  return Fl::run();
}
