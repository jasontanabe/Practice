#include <iostream>

int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }

  return fib(n-1) + fib(n-2);
}

int fib_it(int n) {
  int first = 0;
  int second = 1;
  int num;
  for (int i = 0; i < n; i++) {
    if (i < 2) {
      num = i;
    } else {
      num = second + first;
      first = second;
      second = num;
    }
    std::cout << num << std::endl;
  }
}

int main() {
/*
  for (int i = 0; i < 10; i++) {
    std::cout << fib(i) << std::endl;
  }
*/
  fib_it(10);
  return 0;
}
