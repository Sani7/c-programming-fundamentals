#include <stdio.h>

int main() {
  max_recursive_calls = 100;
  io_mode = 'w';
  throttle_speed = 0.2;

  // don't touch below this line
  printf("Max recursive calls: %d\n", max_recursive_calls);
  printf("IO mode: %c\n", io_mode);
  printf("Throttle speed: %f\n", throttle_speed);
  return 0;
}