#pragma once
#include <zip.h>
#include "processors/interface.h"

class ZipFile : public FileProcessor<ZipFile> {
    public:
        ZipFile(std::string path) : FileProcessor(path) {};
        
        virtual std::variant<AnalyseResult<ZipFile>, ProcessError<ZipFile, int>> getInfo();
        ~ZipFile() = default;
};