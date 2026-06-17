#include <gtest/gtest.h>
#include "ex2_2.h"

#ifndef ARRAY_2D_GET
#warning "ARRAY_2D_GET is not implemented yet - using stub"
uint8_t dummy_array_2d_get = 0;
#define ARRAY_2D_GET(array, type, row, col)  (dummy_array_2d_get)
#endif

__attribute__((weak)) Array_2d_t* Array_2d_init(size_t size, size_t rows, size_t cols)
{
    return nullptr;
}

__attribute__((weak)) void Array_2d_free(Array_2d_t* array)
{
}

__attribute__((weak)) size_t Array_2d_get_rows(Array_2d_t* array)
{
    return 0;
}

__attribute__((weak)) size_t Array_2d_get_cols(Array_2d_t* array)
{
    return 0;
}

__attribute__((weak)) void* Array_2d_get(Array_2d_t* array, size_t row, size_t col)
{
    return nullptr;
}

TEST(array_2d, init_get_free)
{
    Array_2d_t* x = Array_2d_init(sizeof(double), 2, 2);
    EXPECT_EQ(Array_2d_get_rows(x), 2);
    EXPECT_EQ(Array_2d_get_cols(x), 2);
    EXPECT_EQ(ARRAY_2D_GET(x, 0, 0, double), 0);
    EXPECT_EQ(ARRAY_2D_GET(x, 0, 0, double), 0);
    EXPECT_EQ(ARRAY_2D_GET(x, 0, 0, double), 0);
    EXPECT_EQ(ARRAY_2D_GET(x, 0, 0, double), 0);
    Array_2d_free(x);
}

TEST(array_2d, set_with_get)
{
    Array_2d_t* x = Array_2d_init(sizeof(double), 2, 2);

    ARRAY_2D_GET(x, 0, 0, double) = 1;
    ARRAY_2D_GET(x, 0, 1, double) = 2;
    ARRAY_2D_GET(x, 1, 0, double) = 3;
    ARRAY_2D_GET(x, 1, 1, double) = 4;

    EXPECT_EQ(ARRAY_2D_GET(x, 0, 0, double), 1);
    EXPECT_EQ(ARRAY_2D_GET(x, 0, 1, double), 2);
    EXPECT_EQ(ARRAY_2D_GET(x, 1, 0, double), 3);
    EXPECT_EQ(ARRAY_2D_GET(x, 1, 1, double), 4);

    Array_2d_free(x);
}