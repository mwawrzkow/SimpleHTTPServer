#include "mediaManager.hpp"
#include <fstream>
#include <iostream>
#include <string>

namespace IO{
    //implement methods for mediaManager
    MediaManager::MediaManager(std::string fileDirectory)
    {
        this->fileDirectory = fileDirectory;
    }
    MediaManager::MediaManager()
    {
        //set the file directory to the current directory
        this->fileDirectory = ".";
    }
    MediaManager::MediaManager(const MediaManager &)
    {
    }
    MediaManager MediaManager::operator=(const MediaManager &)
    {
        return *this;
    }
    MediaManager::~MediaManager()
    {
    }
    bool MediaManager::fileExists(std::string fileName)
    {
        std::ifstream infile(fileName);
        return infile.good();
    }
    //implement findFile method for mediaManager jpg and png and mp4 and gif files if they not exist return "" 
    std::string MediaManager::FindFile(std::string fileName)
    {
        //output reqested file location
        std::cout << "[ ] Requested file: " << fileName << std::endl;
        // validate file name for html, css, js files and check if file exists in directory
        if (fileName.find(".jpg") != std::string::npos)
        {
            if (fileExists(fileDirectory + fileName))
            {
                return fileDirectory + fileName;
            }
        }
        else if (fileName.find(".png") != std::string::npos)
        {
            if (fileExists(fileDirectory + fileName))
            {
                return fileDirectory + fileName;
            }
        }
        else if (fileName.find(".mp4") != std::string::npos)
        {
            if (fileExists(fileDirectory + fileName))
            {
                return fileDirectory + fileName;
            }
        }
        else if (fileName.find(".gif") != std::string::npos)
        {
            if (fileExists(fileDirectory + fileName))
            {
                return fileDirectory + fileName;
            }
        }
        else
        {
            // return 404 page
            return "";
        }
        return "";
    }
    //implement getContentType method for mediaManager jpg and png and mp4 and gif files if they not exist return ""
    std::string MediaManager::GetContentType(std::string fileName)
    {
        // validate file name for html, css, js files and check if file exists in directory
        // if (fileName.find(".jpg") != std::string::npos)
        // {
        //     return "image/jpeg";
        // }
        // else if (fileName.find(".png") != std::string::npos)
        // {
        //     return "image/png";
        // }
        // else if (fileName.find(".mp4") != std::string::npos)
        // {
        //     return "video/mp4";
        // }
        // else if (fileName.find(".gif") != std::string::npos)
        // {
        //     return "image/gif";
        // }
        // if (fileName.find(".jpeg") != std::string::npos)
        // {
        //     return "image/jpeg";
        // }
        // else
        // {
        //     // return 404 page
        //     return "";
        // }
        // return "";
        //write it with variable which will be printed out in the console
        std::string contentType = "";
        if (fileName.find("jpg") != std::string::npos)
        {
            contentType = "image/jpeg";
        }
        else if (fileName.find("png") != std::string::npos)
        {
            contentType = "image/png";
        }
        else if (fileName.find("mp4") != std::string::npos)
        {
            contentType = "video/mp4";
        }
        else if (fileName.find("gif") != std::string::npos)
        {
            contentType = "image/gif";
        }
        else if (fileName.find("jpeg") != std::string::npos)
        {
            contentType = "image/jpeg";
        }
        else
        {
            // return 404 page
            contentType = "";
        }
        return contentType;
    }
    MediaManager *MediaManager::getInstance(std::string fileDirectory)
    {
        static MediaManager *instance = new MediaManager(fileDirectory);
        return instance;
    }
    std::vector<std::string> MediaManager::getSupportedMediaTypes()
    {
        std::vector<std::string> mediaTypes;
        mediaTypes.push_back("jpg");
        mediaTypes.push_back("png");
        mediaTypes.push_back("mp4");
        mediaTypes.push_back("gif");
        mediaTypes.push_back("jpeg");
        return mediaTypes;
    }
}