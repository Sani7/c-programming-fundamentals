#include <gtest/gtest.h>
#include "ex1_6.h"

__attribute__((weak)) float get_average(int x, int y, int z) {
    return 0.0;
}

TEST(Exercise1_6, test_get_average) {
    float result = get_average(3, 4, 5);
    EXPECT_EQ(result, 4.0);
}

TEST(Exercise1_6, test_non_integer) {
  float result = get_average(3, 3, 5);
  EXPECT_EQ(result, 11.0 / 3.0);
}

TEST(Exercise1_6, test_average_of_same) {
  float result2 = get_average(10, 10, 10);
  EXPECT_EQ(result2, 10.0);
}

TEST(Exercise1_6, test_average_of_big_numbers) {
  float result3 = get_average(1050, 2050, 2075);
  EXPECT_EQ(result3, 1725.0);
}