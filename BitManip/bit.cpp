#include <iostream>
#include <vector>

using namespace std;

void BitSet(int& bits, int pos, bool is_true) {
  if (is_true) {
    bits |= (1 << pos);
  } else {
    bits &= ~(1 << pos);
  }
}

void BitToggle(int& bits, int pos) {
  bits ^= (1 << pos);
}

bool BitCheck(int bits, int pos) {
  return bits & (1 << pos);
}

int main() {
  return 0;
}
