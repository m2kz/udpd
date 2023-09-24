#include "processors/type/tarFile.h"
#include "processors/type/zipFile.h"
#include <gtest/gtest.h>

TEST(MultipleArchiveTest, OpenCloseFile) {
  auto tarFile = TarFile(std::string("tests/archives/test.tar"));
  tarFile.getInfo();
  ASSERT_TRUE(true);
}