#include <string>
#include <vector>
namespace IO
{
    class FileManager
    {
    private:
        // private atomic singleton variables
        FileManager();
        FileManager(std::string fileDirectory);
        // hold the file directory
        std::string fileDirectory;
        // does file exists
        bool fileExists(std::string fileName);
        FileManager(const FileManager &);

    public:
        // find file in directory
        std::string FindFile(std::string fileName);
        ~FileManager();
        // create atomic singleton instance of file manager class
        static FileManager *getInstance(std::string fileDirectory = ".");
        FileManager operator=(const FileManager &);
        std::string GetContentType(std::string);
        //get string list of supported media file types
        std::vector<std::string> getSupportedFileTypes();
    };

}
