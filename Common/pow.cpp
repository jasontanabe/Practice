#include <iostream>

using namespace std;

int pow(int base, int exp) {
  int val = 1;
  while (exp > 0) {
    val *= base;
    exp--;
  }
  return val;
}

int pow_r(int base, int exp) {
  if (exp == 0) {
    return 1;
  }
  return base * pow(base, exp-1);
}

int main() {
  cout << pow_r(2, 3) << endl;
  return 0;
}
