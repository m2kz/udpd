#pragma once
#include <string>
#include <filesystem>
#include <variant>
#include "processors/error.h"
#include "analyse_result.h"

struct FileBase {
    using error_t = int;
};

template <typename T>
class FileProcessor {
    protected:
        std::filesystem::path filePath = {};
        AnalyseResult<T> analyseResult = {};
        ProcessError<T> processError = {};
    public:
        FileProcessor() = default;
        FileProcessor(std::string path) : filePath(path) {};
        virtual std::variant<AnalyseResult<T>, ProcessError<T>> getInfo() = 0;
        virtual std::string getFilePathString() {
            return filePath.string();
        }
        virtual ~FileProcessor() = default;
};