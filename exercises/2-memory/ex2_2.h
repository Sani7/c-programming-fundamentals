#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct Array_2d_s
{
    size_t rows;
    size_t cols;
    size_t size;
    void* ptr;
    uint8_t data[];
} Array_2d_t;

// Implement the following macros in the header file and functions in ex2_2.h
// #define ARRAY_2D_GET(array, type, row, col)

Array_2d_t* Array_2d_init(size_t size, size_t rows, size_t cols);
void Array_2d_free(Array_2d_t* array);
size_t Array_2d_get_rows(Array_2d_t* array);
size_t Array_2d_get_cols(Array_2d_t* array);
void* Array_2d_get(Array_2d_t* array, size_t row, size_t col);