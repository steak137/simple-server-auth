# simple-server-auth

This C++ program is a basic HTTP server built using the Crow C++ microframework. It handles HTTP GET requests on the "/watan/ilovecats" route and performs simple authentication by checking the provided username and password parameters.

## How It Works

A user sends an HTTP GET request to "/watan/ilovecats".
The program checks the "user" and "password" parameters in the request.
If the parameters are missing, the program returns a 400 Bad Request error.
After obtaining the parameters, it reads user information from the "db/users.json" file.
It compares the user information from the JSON file with the provided parameters.
If a matching user is found, a JSON response indicating successful authentication is returned (HTTP 200).
If no matching user is found, an HTTP 401 response (Unauthorized) is returned, indicating authentication failure.

## Usage

Compile the program: g++ main.cpp -o main -lcrow -lboost_system -lboost_thread -pthread -std=c++20
Create the "db/users.json" file and fill it with the necessary user information.
Run the program: ./main
Send a GET request to "/watan/ilovecats" using a browser or another HTTP client, including the required parameters.

## Notes

- The program utilizes the basic functionalities of Crow to create a simple web server.
- User authentication is performed using information from the "db/users.json" file.
- The server runs on port 80 and is multithreaded.
- This program can be used for simple web services or APIs and is easily customizable due to the fast and lightweight nature of Crow.

## Libraries VCPKG
- vcpkg install crow:x64-windows
- vcpkg install nlohmann-json:x64-windows
