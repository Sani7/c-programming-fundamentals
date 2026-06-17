#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct Array_s
{
    size_t rows;
    size_t size;
    void* ptr;
    uint8_t data[];
} Array_t;

// Implement the following macros in the header file and functions in ex2_1.h
// #define ARRAY_GET(array, type, index)

Array_t* Array_init(size_t size, size_t rows);
void Array_free(Array_t* array);
size_t Array_get_rows(Array_t* array);
void* Array_get(Array_t* array, size_t index);
Array_t Array_reduce(Array_t* array, size_t elements_to_discard);