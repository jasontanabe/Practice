#include <iostream>
#include <string>

/* Print out all permutations of a string */

void merge(std::string current, char new_char, std::string string, int index) {
  if (index > string.size()) {
    std::cout << current << std::endl;
    return;
  }
  for (int i = 0; i < current.size(); i++) {
    merge(current.substr(0, i) + new_char + current.substr(i), 
          string[index], string, index+1);
  }
  merge(current + new_char, string[index], string, index+1);
}

int main() {
  std::string string = "abcdefg";
  merge(string.substr(0, 1), string[1], string, 2);
}
