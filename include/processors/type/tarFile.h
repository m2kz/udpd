#include <archive.h>
#include "processors/interface.h"

class TarFileBase : public FileBase {
public:
    using error_t = int;
};

class TarFile : public FileProcessor<TarFileBase> {
    public:
        using AnalyseResultType = AnalyseResult<TarFileBase>;
        using ProcessErrorType = ProcessError<TarFileBase>;
        TarFile(std::string path) : FileProcessor<TarFileBase>(path) {};
        std::variant<AnalyseResultType, ProcessErrorType> getInfo();
        ~TarFile() = default;
    private:
};