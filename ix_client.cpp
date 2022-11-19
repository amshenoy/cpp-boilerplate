#include <iostream>
#include <ixwebsocket/IXNetSystem.h>
#include <ixwebsocket/IXNetSystem.h>
#include <ixwebsocket/IXWebSocket.h>
#include <ixwebsocket/IXUserAgent.h>

int main()
{
    ix::initNetSystem();
    ix::WebSocket webSocket;
    
    std::string url("wss://prod-pusher.backend-capital.com/app/app_key?protocol=7&client=js&version=4.2.2&flash=true");
    webSocket.setUrl(url);
    std::cout << "Connecting to " << url << "..." << std::endl;

    webSocket.setOnMessageCallback([](const ix::WebSocketMessagePtr& msg)
        {
            if (msg->type == ix::WebSocketMessageType::Message)
            {
                std::cout << "Received message: " << msg->str << std::endl;
                std::cout << "> " << std::flush;
            }
            else if (msg->type == ix::WebSocketMessageType::Open)
            {
                std::cout << "Connection established" << std::endl;
                std::cout << "> " << std::flush;
            }
            else if (msg->type == ix::WebSocketMessageType::Error)
            {
                // Maybe SSL is not configured properly
                std::cout << "Connection error: " << msg->errorInfo.reason << std::endl;
                std::cout << "> " << std::flush;
            }
        }
    );

    webSocket.start();
    //webSocket.send("{\"event\":\"pusher:subscribe\",\"data\":{\"channel\":\"27045129890124996\"}}");
    std::cout << "> " << std::flush;
    std::string text;
    while (std::getline(std::cin, text))
    {
        webSocket.send(text);
        std::cout << "> " << std::flush;
    }
    return 0;
}