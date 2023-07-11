#include <zip.h>
#include <iostream>
#include "processors/type/zipFile.h"

using AnalyseResultType = ZipFile::AnalyseResultType;
using ProcessErrorType = ZipFile::ProcessErrorType;

std::variant<AnalyseResultType, ProcessErrorType> ZipFile::getInfo() {
    int err = 0;
    const auto& fileHandler = zip_open(this->getFilePathString().c_str(), 0, &err);
    // Check if it was opened successfully
    if (fileHandler == nullptr) {
        std::cerr << "Error opening zip archive" << std::endl;
        zip_error_t ziperror;
        zip_error_init_with_code(&ziperror, err);
        int zip_err = zip_error_code_zip(&ziperror);
        int sys_err = zip_error_code_system(&ziperror);
        return ProcessErrorType(zip_err);
    }

    zip_int64_t num_entries = zip_get_num_entries(fileHandler, 0);
    std::cout << "The archive contains " << num_entries << " files" << std::endl;

    zip_close(fileHandler);

    return AnalyseResultType();
}