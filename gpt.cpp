#include <iostream>
#include <curl/curl.h>
#include <string>
#include <json/json.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/fl_draw.H>
using namespace std;
std::string response_data;
std::string apiKey = "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";


void input_cb(Fl_Widget*, void* v) {
  Fl_Input *i = (Fl_Input*)v;
  Fl_Output *o = (Fl_Output*)(i->parent()->child(1));
  o->value(i->value());
}

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* userp)
{
response_data.append(buf, size * nmemb);
return size * nmemb;
}

int main(int argc, char **argv)
{ 
	CURL* curl;
CURLcode res;
string prompt;
string gpt_output;

//
Fl_Window *win = new Fl_Window(300, 200, "Dark Mode Form");
  win->color(fl_rgb_color(50,50,50));

  Fl_Input *input = new Fl_Input(100, 50, 150, 30, "Name:");
  input->textcolor(fl_rgb_color(250,250,250));
  input->color(fl_rgb_color(30,30,30));
  input->when(FL_WHEN_ENTER_KEY);
  input->callback(input_cb, input);

  Fl_Output *output = new Fl_Output(100, 100, 150, 30, "Hello,");
  output->textcolor(fl_rgb_color(250,250,250));
  output->color(fl_rgb_color(30,30,30));

  win->end();
  win->show(argc, argv);



//

while (true) {
    
    cout << "Enter text: ";
    getline(std::cin, prompt);

    if (prompt.empty()) {
        break;
    }

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
        } else {
            nlohmann::json response_json = nlohmann::json::parse(response_data);
            std::cout << std::endl<< response_json["choices"][0]["text"].get<std::string>() << std::endl<<std::endl;
        }
        curl_easy_cleanup(curl); 
        
        }
    
}
return 0;
}



//






/*
int main(int argc, char **argv) {
  
  return Fl::run();
}

*/

