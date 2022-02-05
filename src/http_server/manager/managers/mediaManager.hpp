#include <string>
#include <vector>
namespace IO{
    //create class mediaManager which does mostly the same as the fileManager class but for media files
    class MediaManager{
    private:
        //create enum which holds supported media file types
        // private atomic singleton variables
        MediaManager();
        MediaManager(std::string fileDirectory);
        // hold the file directory
        std::string fileDirectory;
        // does file exists
        bool fileExists(std::string fileName);
        MediaManager(const MediaManager &);

    public:
        // find file in directory
        std::string FindFile(std::string fileName);
        ~MediaManager();
        // create atomic singleton instance of file manager class
        static MediaManager *getInstance(std::string fileDirectory = ".");
        MediaManager operator=(const MediaManager &);
        std::string GetContentType(std::string);
        //get string list of supported media file types
        std::vector<std::string> getSupportedMediaTypes();
    };


}