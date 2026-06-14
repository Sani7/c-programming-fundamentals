#include <gtest/gtest.h>
#include "ex1_7.h"

__attribute__((weak)) float score(int num_files, int num_contributors, int num_commits, float avg_bug_criticality) {
    return 0.0;
}

TEST(Exercise1_7, test_score_1) {
  float result = score(3, 4, 5, 0.1);
  EXPECT_EQ(result, 1.9);
}

TEST(Exercise1_7, test_score_2) {
  float result = score(10, 10, 10, 0.1);
  EXPECT_EQ(result, 11.0);
}

TEST(Exercise1_7, test_score_3) {
  float result = score(105, 205, 207, 0.1);
  EXPECT_EQ(result, 2194.0);
}