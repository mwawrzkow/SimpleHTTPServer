#pragma once

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

namespace http_server
{

class RequestHandler : public Poco::Net::HTTPRequestHandler
{
  private: 
    //check the requested file type and return the correct handler
    void* GetHandler(std::string file_type);

    // read file and return std::stringstream using handler
    std::stringstream ReadFile(std::string filePath, void* handler);   
  private: 
    //implement methods for post and get requests
    void handleGetRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);
    void handlePostRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);
public:
  virtual void handleRequest(
      Poco::Net::HTTPServerRequest &req, 
      Poco::Net::HTTPServerResponse &resp);
};

}