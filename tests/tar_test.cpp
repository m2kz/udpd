#include <gtest/gtest.h>
#include "processors/type/tarFile.h"

TEST(TarTest, OpenCloseFile) {
    auto tarFile = TarFile(std::string("tests/archives/test.tar"));
    tarFile.getInfo();
    ASSERT_TRUE(true);
}