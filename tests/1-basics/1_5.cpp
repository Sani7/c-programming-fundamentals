#include <gtest/gtest.h>

__attribute__((weak)) int max_memory(int, int) {
    return 0;
}

TEST(Exercise1_5, Test1) {
    // Arrange
    int threads = 5;
    int memory_per_thread = 5;
    int expected_output = 25; // Assuming the function squares the input

    // Act
    int actual_output = max_memory(threads, memory_per_thread); // Replace with the actual function name

    // Assert
    EXPECT_EQ(expected_output, actual_output);
}

TEST(Exercise1_5, Test2) {
    // Arrange
    int threads = 10;
    int memory_per_thread = 10;
    int expected_output = 100; // Assuming the function squares the input

    // Act
    int actual_output = max_memory(threads, memory_per_thread); // Replace with the actual function name

    // Assert
    EXPECT_EQ(expected_output, actual_output);
}

TEST(Exercise1_5, Test3) {
    // Arrange
    int threads = 1;
    int memory_per_thread = 10;
    int expected_output = 10; // Assuming the function multiplies the inputs

    // Act
    int actual_output = max_memory(threads, memory_per_thread); // Replace with the actual function name

    // Assert
    EXPECT_EQ(expected_output, actual_output);
}

TEST(Exercise1_5, Test4) {
    // Arrange
    int threads = 2;
    int memory_per_thread = 7;
    int expected_output = 14; // Assuming the function multiplies the inputs

    // Act
    int actual_output = max_memory(threads, memory_per_thread); // Replace with the actual function name

    // Assert
    EXPECT_EQ(expected_output, actual_output);
}