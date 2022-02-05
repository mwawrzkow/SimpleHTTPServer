#include "fileManager.hpp"
#include <fstream>
#include <iostream>
namespace IO
{

    FileManager::FileManager(std::string fileDirectory)
    {
        this->fileDirectory = fileDirectory;
    }
    FileManager::FileManager()
    {
        //set the file directory to the current directory
        this->fileDirectory = ".";
    }
    FileManager::FileManager(const FileManager &)
    {
    }
    FileManager FileManager::operator=(const FileManager &)
    {
        return *this;
    }
    FileManager::~FileManager()
    {
    }
    bool FileManager::fileExists(std::string fileName)
    {
        std::ifstream infile(fileName);
        return infile.good();
    }

    std::string FileManager::FindFile(std::string fileName)
    {
        //output reqested file location
        std::cout << "[ ] Requested file: " << fileName << std::endl;
        // validate file name for html, css, js files and check if file exists in directory
        if (fileName.find(".html") != std::string::npos)
        {
            if (fileExists(fileDirectory + fileName))
            {
                return fileDirectory + fileName;
            }
        }
        else if (fileName.find(".css") != std::string::npos)
        {
            if (fileExists(fileDirectory + fileName))
            {
                return fileDirectory + fileName;
            }
        }
        else if (fileName.find(".js") != std::string::npos)
        {
            if (fileExists(fileDirectory + fileName))
            {
                return fileDirectory + fileName;
            }
        }
        else
        {
            // return 404 page
            return fileDirectory + "404.html";
        }
        // return 404 page
        return "404.html";
    }
    FileManager *FileManager::getInstance(std::string fileDirectory)
    {
        static FileManager *instance = new FileManager(fileDirectory);
        return instance;
    }
    // get the content type of the file
    std::string FileManager::GetContentType(std::string fileName)
    {
        if (fileName.find(".html") != std::string::npos)
        {
            return "text/html";
        }
        else if (fileName.find(".css") != std::string::npos)
        {
            return "text/css";
        }
        else if (fileName.find(".js") != std::string::npos)
        {
            return "text/javascript";
        }
        else
        {
            return "text/html";
        }
    }

    std::vector<std::string> FileManager::getSupportedFileTypes(){
        // create a vector of strings to hold the supported file types for the file manager
        std::vector<std::string> supportedFileTypes;
        // add the supported file types to the vector
        supportedFileTypes.push_back("html");
        supportedFileTypes.push_back("css");
        supportedFileTypes.push_back("js");
        // return the vector
        return supportedFileTypes;
    }

} // namespace io
