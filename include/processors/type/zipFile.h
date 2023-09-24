#pragma once
#include "processors/interface.h"
#include <zip.h>

class ZipFileBase : public FileBase {
public:
  using error_t = int;
};

class ZipFile : public FileProcessor<ZipFileBase> {
public:
  using AnalyseResultType = AnalyseResult<ZipFileBase>;
  using ProcessErrorType = ProcessError<ZipFileBase>;
  ZipFile(const ZipFile &) = default;
  ZipFile(ZipFile &&) = delete;
  ZipFile &operator=(const ZipFile &) = delete;
  ZipFile &operator=(ZipFile &&) = delete;
  ZipFile(std::string path) : FileProcessor(path){};
  virtual std::variant<AnalyseResultType, ProcessErrorType> getInfo() final;
  ~ZipFile() override = default;

private:
  AnalyseResultType result = {};
  ProcessErrorType error;
};