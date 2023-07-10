#pragma once
#include <string>
#include <filesystem>
#include <variant>
#include "processors/error.h"
#include "analyse_result.h"

template <typename T>
class FileProcessor {
    protected:
        std::filesystem::path filePath = {};
        AnalyseResult<T> analyseResult = {};
        template <typename S>
        ProcessError<T, S> processError = {};
    public:
        FileProcessor(std::string path) : filePath(path) {};
        template <typename S>
        virtual std::variant<AnalyseResult<T>, ProcessError<T, S>> getInfo() = 0;
        virtual std::string getFilePathString() {
            return filePath.string();
        }
        virtual ~FileProcessor() = default;
};