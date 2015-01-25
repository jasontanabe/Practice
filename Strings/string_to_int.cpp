#include <iostream>

using namespace std;

int char_to_int(char c) {
  switch(c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
  }
}

int string_to_int(const char* num_str) {
  int num = 0;
  int val = 0;
  while (*num_str) {
    num *= 10;
    num += char_to_int(*num_str);
    num_str++;
  }
  return num;
}

int main() {
  const char number[] = "1234";
  int num = string_to_int(number);
  cout << num << endl;
  return 0;
}
