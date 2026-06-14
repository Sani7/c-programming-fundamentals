#include <gtest/gtest.h>
#include "ex1_14.h"

__attribute__((unused)) void set_bit(uint64_t *array, size_t size, size_t index, uint8_t state) {
    
}

__attribute__((unused)) uint8_t check_bit(uint64_t *array, size_t size, size_t index) {
    return 0;
}

TEST(BitwiseOperations, SetBit) {
    uint64_t array[2] = {0, 0};

    set_bit(array, 2, 0, 1);
    EXPECT_EQ(array[0], 1);

    set_bit(array, 2, 63, 1);
    EXPECT_EQ(array[0], 1ULL << 63);

    set_bit(array, 2, 64, 1);
    EXPECT_EQ(array[1], 1);

    set_bit(array, 2, 127, 1);
    EXPECT_EQ(array[1], (1ULL << 63) | 1);

    set_bit(array, 2, 64, 0);
    EXPECT_EQ(array[1], 0);

    set_bit(array, 2, 0, 0);
    EXPECT_EQ(array[0], 0);

}

TEST(BitwiseOperations, CheckBit) {
    uint64_t array[2] = {0b10010101, 1ULL << 63};
    EXPECT_EQ(check_bit(array, 2, 0), 1);
    EXPECT_EQ(check_bit(array, 2, 1), 0);
    EXPECT_EQ(check_bit(array, 2, 2), 1);
    EXPECT_EQ(check_bit(array, 2, 3), 0);
    EXPECT_EQ(check_bit(array, 2, 4), 1);
    EXPECT_EQ(check_bit(array, 2, 5), 0);
    EXPECT_EQ(check_bit(array, 2, 6), 0);
    EXPECT_EQ(check_bit(array, 2, 7), 1);
    EXPECT_EQ(check_bit(array, 2, 63), 1);
    array[0] = 0;
    array[1] = 0;
    EXPECT_EQ(check_bit(array, 2, 0), 0);
    EXPECT_EQ(check_bit(array, 2, 63), 0);
}