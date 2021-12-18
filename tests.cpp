#include <gtest/gtest.h>
#include "main.c"

using testing::Eq;

int wordcount(int argc, char *argv[3]);

TEST(mult_test, some_values) {
    ASSERT_EQ(mult(2, 4), 8);
    ASSERT_EQ(mult(0, 1), 0);
}

TEST(wordCountTest, two_lines) {
    char *arr[3] = {"WordCount.exe", "-l", "threeLines.txt"};
    ASSERT_EQ(wordcount(3, arr), 3);
    char *arr1[3] = {"WordCount.exe", "-c", "threeLines.txt"};
    ASSERT_EQ(wordcount(3, arr1), 72);
    char *arr2[3] = {"WordCount.exe", "-w", "threeLines.txt"};
    ASSERT_EQ(wordcount(3, arr2), 17);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
