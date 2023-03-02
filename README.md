# Simple-Chatbox-with-ChatGPT-API-FLTK
[![Chatbox](https://img.shields.io/badge/chatbox-application-orange)](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox) [![GitHub top language](https://img.shields.io/github/languages/top/vonnogadas/Simple-Chatbox-with-ChatGPT-API-FLTK-?color=blue)](https://gcc.gnu.org/) [![Bitbucket open issues](https://img.shields.io/bitbucket/issues/vonnogadas/Simple-Chatbox-with-ChatGPT-API-FLTK-)](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox/issues)

A simple chatbox application that utilizes the OpenAI ChatGPT API, with cURL and JSON libraries for api communication and fltk for the GUI.



[![Snapshots](https://img.shields.io/badge/snapshots-6-brightgreen)](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox/tree/main/preview)

![ Preview ](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox/blob/5b244ac788f0fc0061328fb3a7b2f3221d5f2548/preview/npreview1.png) .
![ Preview ](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox/blob/1a5d5eca6394d256fcbcebd594b842fe27fdc6be/preview/npreview2.png)
![ Preview ](https://github.com/vonnogadas/ChatGPT-FLTK-Simple-Chatbox/blob/1a5d5eca6394d256fcbcebd594b842fe27fdc6be/preview/npreview3.png)

## Running the program
```
g++ -o main main.cpp -lcurl -lfltk -lfltk_images
```
**Notes:** Before running, make sure to add your api key to the string variable *apiKey* at the top of the program. Otherwise, curl wouldn't be able to connect to chatGPT.

---

## Dependencies
### Installing C++
C++ is usually pre-installed in most Linux distributions. To check if you have C++ installed, open the terminal and run the following command:

```
g++ -v
```
If you do not have C++ installed, you can install it by running the following command:
```
sudo apt-get update
sudo apt-get install build-essential
```

### Installing curl
Curl is a network transfer library used to retrieve data from web servers. You can install curl by running the following command:
```
sudo apt-get update
sudo apt-get install curl libcurl4-openssl-dev
```

### Installing nlohmann/json
nlohmann/json is a header-only library for JSON data format in C++. It is easy to use and does not require any additional installation. To use the library in your project, simply include the following line in your code:
```cpp
#include <nlohmann/json.hpp>
```

## Installing FLTK
FLTK (Fast Light Toolkit) is a C++ graphical user interface library. You can install FLTK by running the following command:
```
sudo apt-get update
sudo apt-get install libfltk1.3-dev
```

