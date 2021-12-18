#include <gtest/gtest.h>
#include "main.c"

using testing::Eq;

int wordcount(int argc, char *argv[3]);

TEST(wordCountTest, empty_file) {
    ASSERT_EQ(mult(2, 4), 8);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
