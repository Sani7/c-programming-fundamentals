#include <stdio.h>

void print_numbers_reverse(int start, int end) {
  while (start >= end) {
    printf("%d\n", start);
    start--;
  }
}

void test(int start, int end) {
  printf("print_numbers_reverse(start=%d, end=%d):\n", start, end);
  print_numbers_reverse(start, end);
  printf("======================\n");
}

int main() {
  test(5, 1);
  test(1, 5);
}