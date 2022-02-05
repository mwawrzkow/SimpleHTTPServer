#include <thread>
#include <iostream>
#include "http_server/HttpServer.h"

constexpr int SERVER_PORT = 8088;


int main()
{
    http_server::HttpServer server(SERVER_PORT);
    server.Start();
    //keep the program running until the user hits enter
    std::cin.get();
    server.Stop();

    return 0;
}
