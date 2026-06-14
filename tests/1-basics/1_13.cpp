#include <gtest/gtest.h>
#include "ex1_13.h"

TEST(Exercise1_13, test_is_a_palindrome) {
  EXPECT_EQ(is_a_palindrome("racecar"), 1);
  EXPECT_EQ(is_a_palindrome("noon"), 1);
  EXPECT_EQ(is_a_palindrome("level"), 1);
  EXPECT_EQ(is_a_palindrome("rotor"), 1);
  EXPECT_EQ(is_a_palindrome("hello"), 0);
  EXPECT_EQ(is_a_palindrome("world"), 0);
  EXPECT_EQ(is_a_palindrome("test"), 0);
}

TEST(Exercise1_13, test_is_a_palindrome_sentence) {
    EXPECT_EQ(is_a_palindrome_sentence("Was it a car or a cat I saw."), 1);
    EXPECT_EQ(is_a_palindrome_sentence("Eva, can I stab bats in a cave?"), 1);
    EXPECT_EQ(is_a_palindrome_sentence("A man, a plan, a canal, Panama!"), 1);
    EXPECT_EQ(is_a_palindrome_sentence("Hello, world!"), 0);
    EXPECT_EQ(is_a_palindrome_sentence("This is not a palindrome."), 0);
    EXPECT_EQ(is_a_palindrome_sentence("Not a palindrome sentence."), 0);
}

TEST(Exercise1_13, test_is_an_panagram) {
    EXPECT_EQ(is_an_panagram("The quick brown fox jumps over the lazy dog."), 1);
    EXPECT_EQ(is_an_panagram("Pack my box with five dozen liquor jugs."), 1);
    EXPECT_EQ(is_an_panagram("Sphinx of black quartz, judge my vow."), 1);
    EXPECT_EQ(is_an_panagram("Hello, world!"), 0);
    EXPECT_EQ(is_an_panagram("This is not a pangram."), 0);
    EXPECT_EQ(is_an_panagram("Not a pangram sentence."), 0);
}