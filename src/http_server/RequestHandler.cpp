#include "RequestHandler.h"
#include "manager/coreManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace Poco::Net;
using http_server::RequestHandler;

void RequestHandler::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
{
  // determine if the request is a get or post request
  if (req.getMethod() == HTTPRequest::HTTP_GET)
  {
    handleGetRequest(req, resp);
  }
  else if (req.getMethod() == HTTPRequest::HTTP_POST)
  {
    handlePostRequest(req, resp);
  }
  else
  {
    resp.setStatus(HTTPResponse::HTTP_BAD_REQUEST);
  }
}

void RequestHandler::handleGetRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
{
  // if the request is a get request, ask for instance of file handler

  // get the file path from the request
  std::string file_path = req.getURI();
  // if the file path is / request the index file
  if (file_path == "/")
  {
    file_path = "/index.html";
  }
  // get the file type from the file path

  std::string file_type = file_path.substr(file_path.find_last_of(".") + 1);
  // get the file handler

  void *handler = GetHandler(file_type);

  // if the file handler is null, return bad request
  if (handler == nullptr)
  {
    resp.setStatus(HTTPResponse::HTTP_BAD_REQUEST);
    return;
  }
  // read the file and return the file contents


  //send image

  
  
  // set the content type
  //get supported file types from file manager and media manager
  std::vector<std::string> supported_file_types = IO::FileManager::getInstance()->getSupportedFileTypes();
  std::vector<std::string> supported_media_types = IO::MediaManager::getInstance()->getSupportedMediaTypes();
  // if the file type is in the supported file types vector, get the content type from the coresponding manager
  bool isImage = false;
  std::string media_type; 
  if (std::find(supported_file_types.begin(), supported_file_types.end(), file_type) != supported_file_types.end())
  {
    //set media_type to the content type of the file
    media_type = IO::FileManager::getInstance()->GetContentType(file_path);
  }else if (std::find(supported_media_types.begin(), supported_media_types.end(), file_type) != supported_media_types.end())
  {
    isImage = true;
    media_type = IO::MediaManager::getInstance()->GetContentType(file_path);
  }
  // if the file type is not in the supported file types vector, return bad request
  else
  {
    resp.setStatus(HTTPResponse::HTTP_BAD_REQUEST);
    return;
  }
  // if the file type is an image, send the image using POCO 
  if (isImage)
  {
    //show file_path
    //set path to relative path
    std::string path = file_path.substr(1);
    resp.sendFile(path,media_type );
  }else {
  // resp.setContentLength(file_contents.str().length());
  // write the file contents to the response using the out stream
  resp.setContentType(media_type);
  std::stringstream file_contents = ReadFile(file_path, handler);
  std::ostream &out = resp.send();
  out << file_contents.str();
  // flush the output stream
  out.flush();
  // set the status to ok
  resp.setStatus(HTTPResponse::HTTP_OK);
  }

}
void *RequestHandler::GetHandler(std::string file_type)
{
  // get getSupportedFileTypes
  std::vector<std::string> supported_file_types = IO::UtilManager::getFileManager()->getSupportedFileTypes();
  // iterate through the supported file types
  for (std::vector<std::string>::iterator it = supported_file_types.begin(); it != supported_file_types.end(); ++it)
  {
    // if the file type is equal to the current supported file type
    if (*it == file_type)
    {
      // if the filetype is supported return the handler

      return IO::UtilManager::getFileManager();
    }
  }
  // get supported media typesŚ
  std::vector<std::string> supported_media_types = IO::UtilManager::getMediaManager()->getSupportedMediaTypes();
  // iterate through the supported media types
  for (std::vector<std::string>::iterator it = supported_media_types.begin(); it != supported_media_types.end(); ++it)
  {
    // if the file type is equal to the current supported media type
    if (*it == file_type)
    {
      // if the filetype is supported return the handler

      return IO::UtilManager::getMediaManager();
    }
  }

  return nullptr;
}
std::stringstream RequestHandler::ReadFile(std::string filePath, void *handler)
{
  try
  {
    IO::FileManager *file_handler = (IO::FileManager *)handler;
    // get the file contents
    std::string file_contents = file_handler->FindFile(filePath);
    // read the file contents
    std::ifstream file_stream(file_contents);
    std::stringstream file_buffer;
    file_buffer << file_stream.rdbuf();
    // return the file buffer
    return file_buffer;
  }
  catch (std::exception &e)
  {
    IO::MediaManager *media_handler = (IO::MediaManager *)handler;
    // get the file contents
    std::string file_contents = media_handler->FindFile(filePath);
    // read the file contents
    std::ifstream file_stream(file_contents);
    std::stringstream file_buffer;
    file_buffer << file_stream.rdbuf();
    // return the file buffer
    return file_buffer;
  }
}
// TODO: implement post request

void RequestHandler::handlePostRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
{
}