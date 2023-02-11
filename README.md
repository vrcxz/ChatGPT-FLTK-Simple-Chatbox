# Simple-Chatbox-with-ChatGPT-API-FLTK
![Chatbox](https://img.shields.io/badge/chatbox-application-orange) ![GitHub top language](https://img.shields.io/github/languages/top/vonnogadas/Simple-Chatbox-with-ChatGPT-API-FLTK-?color=blue) ![Bitbucket open issues](https://img.shields.io/bitbucket/issues/vonnogadas/Simple-Chatbox-with-ChatGPT-API-FLTK-)

A simple chatbox application that utilizes the OpenAI ChatGPT API, accessing with cURL and JSON libraries for API communication and the FLTK GUI library for creating a user-friendly interface. With this app, users can engage in natural language conversations with an AI-powered chatbot, powered by the cutting-edge technology of the ChatGPT API. The sleek and intuitive interface, combined with the advanced functionality provided by the API, makes for an engaging and convenient chat experience.



![Snapshots](https://img.shields.io/badge/snapshots-6-brightgreen)

![ Preview ](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox/blob/5b244ac788f0fc0061328fb3a7b2f3221d5f2548/preview/npreview1.png) .
![ Preview ](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox/blob/1a5d5eca6394d256fcbcebd594b842fe27fdc6be/preview/npreview2.png)
![ Preview ](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox/blob/1a5d5eca6394d256fcbcebd594b842fe27fdc6be/preview/npreview3.png)

## Running the program
```
g++ -o main main.cpp -lcurl -lfltk -lfltk_images
```

## Installing C++
C++ is usually pre-installed in most Linux distributions. To check if you have C++ installed, open the terminal and run the following command:

```
g++ -v
```
If you do not have C++ installed, you can install it by running the following command:
```
sudo apt-get update
sudo apt-get install build-essential
```

## Installing curl
Curl is a network transfer library used to retrieve data from web servers. You can install curl by running the following command:
```
sudo apt-get update
sudo apt-get install curl libcurl4-openssl-dev
```

## Installing nlohmann/json
nlohmann/json is a header-only library for JSON data format in C++. It is easy to use and does not require any additional installation. To use the library in your project, simply include the following line in your code:
```
#include <nlohmann/json.hpp>
```

## Installing FLTK
FLTK (Fast Light Toolkit) is a C++ graphical user interface library. You can install FLTK by running the following command:
```
sudo apt-get update
sudo apt-get install libfltk1.3-dev
```
