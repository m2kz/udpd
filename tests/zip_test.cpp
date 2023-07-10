#include <gtest/gtest.h>
#include "processors/type/zipFile.h"

TEST(ZipTest, OpenCloseFile) {
    auto zipFile = ZipFile(std::string("tests/archives/test.zip"));
    zipFile.getInfo();
    ASSERT_TRUE(true);
}