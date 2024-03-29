#include <archive_entry.h>
#include "processors/type/tarFile.h"

using AnalyseResultType = TarFile::AnalyseResultType;
using ProcessErrorType = TarFile::ProcessErrorType;

std::variant<AnalyseResultType, ProcessErrorType> TarFile::getInfo() {
    struct archive *archiveFile;
    struct archive_entry *entry;
    int result;

    archiveFile = archive_read_new();
    archive_read_support_format_tar(archiveFile);

    const size_t fileSize = 10240;
    result = archive_read_open_filename(archiveFile, this->getFilePathString().c_str(), fileSize);
    if (result != ARCHIVE_OK) {
        return ProcessErrorType(result);
    }

    while (archive_read_next_header(archiveFile, &entry) == ARCHIVE_OK) {
        printf("%s\n", archive_entry_pathname(entry));
        archive_read_data_skip(archiveFile);
    }

    result = archive_read_free(archiveFile);
    if (result != ARCHIVE_OK) {
        return ProcessErrorType(result);
    }

    return AnalyseResultType();
}