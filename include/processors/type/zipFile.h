#pragma once
#include <zip.h>
#include "processors/interface.h"

class ZipFileBase : public FileBase {
public:
    using error_t = int;
};

class ZipFile : public FileProcessor<ZipFileBase> {
    public:
        using AnalyseResultType = AnalyseResult<ZipFileBase>;
        using ProcessErrorType = ProcessError<ZipFileBase>;
        ZipFile(std::string path) : FileProcessor(path) {};
        virtual std::variant<AnalyseResultType, ProcessErrorType> getInfo();
        ~ZipFile() = default;
    private:
        AnalyseResultType result = {};
        ProcessErrorType error;
};