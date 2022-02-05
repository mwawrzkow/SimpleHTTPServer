#include "managers/mediaManager.hpp"
#include "managers/fileManager.hpp"
namespace IO{
    //implement singletone coreManager class which holds the fileManager and mediaManager instances
    namespace UtilManager{
        IO::FileManager *getFileManager();
        IO::MediaManager *getMediaManager();
    }
}