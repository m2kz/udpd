#include <archive.h>
#include "processors/interface.h"

class TarFile : public FileProcessor<TarFile> {

    public:
        TarFile(std::string path) : FileProcessor<TarFile>(path) {};
        std::variant<AnalyseResult<TarFile>, ProcessError<TarFile, int>> getInfo();
        ~TarFile() = default;
};