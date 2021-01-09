#include "version.h"
#include <gtest/gtest.h>

TEST(Test_app, Test_Version) {
    int version = PROJECT_VERSION_PATCH;
    ASSERT_GT(version, 0);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}