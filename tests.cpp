#include <gtest/gtest.h>
#include "main.c"

using testing::Eq;

int wordcount(int argc, char *argv[3]);

TEST(mult_test, some_values) {
    ASSERT_EQ(mult(2, 4), 8);
    ASSERT_EQ(mult(0, 1), 0);
}

TEST(wordCountTest, empty_file) {
    char *arr[3] = {"WordCount.exe", "-l", ".empty.txt"};
    ASSERT_EQ(wordcount(3, arr), 0);
    char *arr1[3] = {"WordCount.exe", "-c", "empty.txt"};
    ASSERT_EQ(wordcount(3, arr1), 0);
    char *arr2[3] = {"WordCount.exe", "-w", "empty.txt"};
    ASSERT_EQ(wordcount(3, arr2), 0);
}

TEST(wordCountTest, empty_file_with_two_lines) {
    char *arr[3] = {"WordCount.exe", "-l",
                    "emptyWithTwoLines.txt"};
    ASSERT_EQ(wordcount(3, arr), 2);
    char *arr1[3] = {"WordCount.exe", "-c",
                     "emptyWithTwoLines.txt"};
    ASSERT_EQ(wordcount(3, arr1), 1);
    char *arr2[3] = {"WordCount.exe", "-w",
                     "emptyWithTwoLines.txt"};
    ASSERT_EQ(wordcount(3, arr2), 0);
}

TEST(wordCountTest, two_lines) {
    char *arr[3] = {"WordCount.exe", "-l", "threeLines.txt"};
    ASSERT_EQ(wordcount(3, arr), 3);
    char *arr1[3] = {"WordCount.exe", "-c", "threeLines.txt"};
    ASSERT_EQ(wordcount(3, arr1), 72);
    char *arr2[3] = {"WordCount.exe", "-w", "threeLines.txt"};
    ASSERT_EQ(wordcount(3, arr2), 17);
}


TEST(wordCountTest, different_occurring_errors) {
    char *arr[3] = {"WordCount.exe", "--myNameJef", "threeLines.txt"};
    ASSERT_EQ(wordcount(3, arr), -2);
    char *arr1[3] = {"WordCount.exe", "-c", "NOTEXISTINGFILE.txt"};
    ASSERT_EQ(wordcount(3, arr1), -1);
}

TEST(wordCountTest, bigFile) {
    char *arr[3] = {"WordCount.exe", "-c", "bigFile.txt"};
    ASSERT_EQ(wordcount(3, arr), 7926);

    char *arr1[3] = {"WordCount.exe", "-l", "bigFile.txt"};
    ASSERT_EQ(wordcount(3, arr1), 61);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
