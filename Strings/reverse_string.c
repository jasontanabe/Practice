#include <stdio.h>

/* reverse a string in place */

int main(int argc, char** argv) {
  char str[] = "abcd";
  if (!str) {
    return;
  }
  char* start = str;
  char* end = str;
  char tmp;
  while (*end) {
    end++;
  }
  end--;
  while (end > start) {
    tmp = *end;
    *end = *start;
    *start = tmp;
    end--;
    start++;
  }
  printf("%s\n", str);
}

