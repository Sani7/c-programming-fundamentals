#include <gtest/gtest.h>
#include "ex2_1.h"

#ifndef ARRAY_GET
#warning "ARRAY_GET is not implemented yet - using stub"
uint8_t dummy_array_get = 0;
#define ARRAY_GET(array, type, index)  (dummy_array_get)
#endif

__attribute__((weak)) Array_t* Array_init(size_t size, size_t rows)
{
    return nullptr;
}

__attribute__((weak)) void Array_free(Array_t* array)
{
}

__attribute__((weak)) size_t Array_get_rows(Array_t* array)
{
    return 0;
}

__attribute__((weak)) void* Array_get(Array_t* array, size_t index)
{
    return nullptr;
}

__attribute__((weak)) Array_t Array_reduce(Array_t* array, size_t elements_to_discard)
{
    return {};
}

TEST(array, init)
{
    Array_t* x = Array_init(sizeof(double), 2);
    EXPECT_EQ(Array_get_rows(x), 2);
    EXPECT_EQ(ARRAY_GET(x, 0, double), 0);
    EXPECT_EQ(ARRAY_GET(x, 0, double), 0);
    Array_free(x);
}

TEST(array, reduce)
{
    Array_t* x = Array_init(sizeof(double), 10);
    ARRAY_GET(x, 0, double) = 1;
    ARRAY_GET(x, 1, double) = 2;
    ARRAY_GET(x, 2, double) = 3;
    ARRAY_GET(x, 3, double) = 4;
    ARRAY_GET(x, 4, double) = 5;
    ARRAY_GET(x, 5, double) = 6;
    ARRAY_GET(x, 6, double) = 7;
    ARRAY_GET(x, 7, double) = 8;
    ARRAY_GET(x, 8, double) = 9;
    ARRAY_GET(x, 9, double) = 10;

    Array_t y = Array_reduce(x, 1);
    EXPECT_EQ(Array_get_rows(&y), 9);

    EXPECT_EQ(ARRAY_GET(&y, 0, double), 2);
    EXPECT_EQ(ARRAY_GET(&y, 1, double), 3);
    EXPECT_EQ(ARRAY_GET(&y, 2, double), 4);
    EXPECT_EQ(ARRAY_GET(&y, 3, double), 5);
    EXPECT_EQ(ARRAY_GET(&y, 4, double), 6);
    EXPECT_EQ(ARRAY_GET(&y, 5, double), 7);
    EXPECT_EQ(ARRAY_GET(&y, 6, double), 8);
    EXPECT_EQ(ARRAY_GET(&y, 7, double), 9);
    EXPECT_EQ(ARRAY_GET(&y, 8, double), 10);

    y = Array_reduce(x, 5);
    EXPECT_EQ(Array_get_rows(&y), 5);
    EXPECT_EQ(ARRAY_GET(&y, 0, double), 6);
    EXPECT_EQ(ARRAY_GET(&y, 1, double), 7);
    EXPECT_EQ(ARRAY_GET(&y, 2, double), 8);
    EXPECT_EQ(ARRAY_GET(&y, 3, double), 9);
    EXPECT_EQ(ARRAY_GET(&y, 4, double), 10);

    y = Array_reduce(x, 10);
    EXPECT_EQ(Array_get_rows(&y), 0);

    Array_free(x);
}


TEST(array, set_with_get)
{
    Array_t* x  = Array_init(sizeof(double), 2);

    ARRAY_GET(x, 0, double) = 1;
    ARRAY_GET(x, 1, double) = 2;

    EXPECT_EQ(ARRAY_GET(x, 0, double), 1);
    EXPECT_EQ(ARRAY_GET(x, 1, double), 2);

    Array_free(x);
}
