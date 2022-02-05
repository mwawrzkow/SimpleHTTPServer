#include "coreManager.hpp"

namespace IO
{
    //implement methods from header
    namespace UtilManager
    {
        //using getInstance method to get the fileManager instance
        IO::FileManager *getFileManager(){
            return IO::FileManager::getInstance();
        }
        IO::MediaManager *getMediaManager(){
            return IO::MediaManager::getInstance();
        }
    }

    
} // namespace IO
