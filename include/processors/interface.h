#include <string>

class FileProcessor {
    public:
        virtual std::string getInfo() = 0;
        virtual ~FileProcessor();
};