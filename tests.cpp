#include <gtest/gtest.h>
#include "main.c"

using testing::Eq;

int wordcount(int argc, char *argv[3]);

TEST(mult_test, some_values) {
    ASSERT_EQ(mult(2, 4), 8);
    ASSERT_EQ(mult(0, 1), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
