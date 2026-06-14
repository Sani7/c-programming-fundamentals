#pragma once
#include <stdint.h>
#include <stddef.h>

void set_bit(uint64_t *array, size_t size, size_t index, uint8_t state);
uint8_t check_bit(uint64_t *array, size_t size, size_t index);