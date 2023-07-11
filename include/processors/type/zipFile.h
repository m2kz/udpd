#pragma once
#include <zip.h>
#include "processors/interface.h"

class ZipFileBase : public FileBase {
public:
    using error_t = int;
};

class ZipFile : public FileProcessor<ZipFileBase> {
    private:
        AnalyseResult<ZipFileBase> result = {};
        ProcessError<ZipFileBase> error;
    public:
        using error_t = int;
        ZipFile(std::string path) : FileProcessor(path) {};
        virtual std::variant<AnalyseResult<ZipFileBase>, ProcessError<ZipFileBase>> getInfo();
        ~ZipFile() = default;
};