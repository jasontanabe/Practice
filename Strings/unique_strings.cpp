#include <iostream>
#include <string>

/* Check to see if a string is unique (no repeating) */

int main() {
  std::string string = "abcdefgb";
  bool characters[256];
  for (int i = 0; i < 256; i++) {
    characters[i] = false;
  }
  for (int i = 0; i < string.size(); i++) {
    if (characters[static_cast<int>(string[i])]) {
      std::cout << "not unique" << std::endl;
      return 0;
    }
    characters[static_cast<int>(string[i])] = true;
  }
  std::cout << "unique" << std::endl;
}


