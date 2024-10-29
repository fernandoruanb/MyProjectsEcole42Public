#include <stdio.h>
int f1(void) {
  return 1;
}
int f2() {
  return 2;
}

int main(void) {
  printf("%d\n", f1());
  printf("%d\n", f2(1, 2, 4));
}
