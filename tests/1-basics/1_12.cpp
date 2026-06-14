#include <gtest/gtest.h>
#include "ex1_12.h"

__attribute__((weak)) int max(int *arr, size_t size) {
    return 0;
}

__attribute__((weak)) int min(int *arr, size_t size) {
    return 0;
}

__attribute__((weak)) int sum(int *arr, size_t size) {
    return 0;
}

__attribute__((weak)) int product(int *arr, size_t size) {
    return 0;
}

__attribute__((weak)) float average(int *arr, size_t size) {
    return 0.0f;
}

__attribute__((weak)) float median(int *arr, size_t size) {
    return 0.0f;
}

TEST(Exercise1_12, test_max_1) {
  int arr[] = {1, 2, 3, 4, 5};
  int result = max(arr, 5);
  EXPECT_EQ(result, 5);
}

TEST(Exercise1_12, test_max_2) {
  int arr[] = {17, 40, 25, 3, 7};
  int result = max(arr, 5);
  EXPECT_EQ(result, 40);
}

TEST(Exercise1_12, test_min_1) {
  int arr[] = {1, 2, 3, 4, 5};
  int result = min(arr, 5);
  EXPECT_EQ(result, 1);
}

TEST(Exercise1_12, test_min_2) {
  int arr[] = {17, 40, 25, 3, 7};
  int result = min(arr, 5);
  EXPECT_EQ(result, 3);
}

TEST(Exercise1_12, test_sum_1) {
  int arr[] = {1, 2, 3, 4, 5};
  int result = sum(arr, 5);
  EXPECT_EQ(result, 15);
}

TEST(Exercise1_12, test_sum_2) {
  int arr[] = {17, 40, 25, 3, 7};
  int result = sum(arr, 5);
  EXPECT_EQ(result, 92);
}

TEST(Exercise1_12, test_product_1) {
  int arr[] = {1, 2, 3, 4, 5};
  int result = product(arr, 5);
  EXPECT_EQ(result, 120);
}

TEST(Exercise1_12, test_product_2) {
  int arr[] = {17, 40, 25, 3, 7};
  int result = product(arr, 5);
  EXPECT_EQ(result, 11900);
}

TEST(Exercise1_12, test_average_1) {
  int arr[] = {1, 2, 3, 4, 5};
  float result = average(arr, 5);
  EXPECT_FLOAT_EQ(result, 3.0f);
}

TEST(Exercise1_12, test_average_2) {
  int arr[] = {17, 40, 25, 3, 7};
  float result = average(arr, 5);
  EXPECT_FLOAT_EQ(result, 23.4f);
}

TEST(Exercise1_12, test_median_1) {
  int arr[] = {1, 2, 3, 4, 5};
  float result = median(arr, 5);
  EXPECT_FLOAT_EQ(result, 3.0f);
}

TEST(Exercise1_12, test_median_2) {
  int arr[] = {17, 40, 25, 3, 7};
  float result = median(arr, 5);
  EXPECT_FLOAT_EQ(result, 25.0f);
}

TEST(Exercise1_12, test_median_3) {
  int arr[] = {17, 40, 25, 3};
  float result = median(arr, 4);
  EXPECT_FLOAT_EQ(result, 21.0f);
}