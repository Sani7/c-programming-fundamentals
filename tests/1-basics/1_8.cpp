#include <gtest/gtest.h>
#include "ex1_8.h"

__attribute__((weak)) char* get_temperature_status(int temp) {
    return nullptr;
}

TEST(Exercise1_8, test_cold) {
  char *result = get_temperature_status(50);
  EXPECT_STREQ(result, "too cold");
}

TEST(Exercise1_8, test_hot) {
  char *result = get_temperature_status(100);
  EXPECT_STREQ(result, "too hot");
}

TEST(Exercise1_8, test_just_right) {
  char *result = get_temperature_status(70);
  EXPECT_STREQ(result, "just right");
}

TEST(Exercise1_8, test_just_right2) {
  char *result = get_temperature_status(75);
  EXPECT_STREQ(result, "just right");
}