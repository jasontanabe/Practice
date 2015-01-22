#include <iostream>

/* Check if one string is a substring of another */

bool IsSubstring(const char* string, const char* substr) {
  const char* start = substr;
  if (*substr == '\0') {
    return false;
  }
  while (*string != '\0') {
    if (*substr == *string) {
      substr++;
    } else {
      substr = start;
      if (*substr == *string) {
        substr++;
      }
    }
    if (*substr == '\0') {
      return true;
    }
    string++;
  }
  return false;
}

int main() {
  const char* string = "bbabbabbat";
  const char* substr = "bat";
  std::cout << IsSubstring(string, substr) << std::endl;
  return 0;
}
