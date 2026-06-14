#include <gtest/gtest.h>
#include "ex1_9.h"

__attribute__((weak)) int can_access_registry(int is_premium, int reputation, int has_2fa) {
    return 0;
}

TEST(Exercise1_9, test_premium_user) {
  int result = can_access_registry(1, 0, 0);
  EXPECT_EQ(result, 1);
}

TEST(Exercise1_9, test_high_rep_with_2fa) {
  int result = can_access_registry(0, 100, 1);
  EXPECT_EQ(result, 1);
}

TEST(Exercise1_9, test_high_rep_no_2fa) {
  int result = can_access_registry(0, 150, 0);
  EXPECT_EQ(result, 0);
}

TEST(Exercise1_9, test_low_rep_with_2fa) {
  int result = can_access_registry(0, 50, 1);
  EXPECT_EQ(result, 0);
}

TEST(Exercise1_9, test_premium_overrides) {
  int result = can_access_registry(1, 10, 0);
  EXPECT_EQ(result, 1);
}

TEST(Exercise1_9, test_no_access) {
  int result = can_access_registry(0, 50, 0);
  EXPECT_EQ(result, 0);
}