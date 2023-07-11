#include <archive.h>
#include "processors/interface.h"

class TarFileBase : public FileBase {
public:
    using error_t = int;
};

class TarFile : public FileProcessor<TarFileBase> {
    private:
    public:
        TarFile(std::string path) : FileProcessor<TarFileBase>(path) {};
        std::variant<AnalyseResult<TarFileBase>, ProcessError<TarFileBase>> getInfo();
        ~TarFile() = default;
};