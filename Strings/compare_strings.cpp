#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

bool char_less_than(char one, char two) {
  if (isalpha(one) && isalpha(two)) {
    return tolower(static_cast<int>(one)) < tolower(static_cast<int>(two));
  } else {
    return static_cast<int>(one) < static_cast<int>(two);
  }
}

int compare_string(const string& one, const string& two) {
  int one_pos = 0;
  int two_pos = 0;
  while (one_pos < one.size() && two_pos < two.size()) {
    if (one[one_pos] != two[two_pos]) {
      return char_less_than(one[one_pos], two[two_pos]);
    }
    one_pos++;
    two_pos++;
  }
  if (one.size() == two.size()) return -1;
  return one.size() < two.size();
}

int main() {
  string one = "jasonbaac";
  string two = "jasonbaa";
  cout << compare_string(one, two) << endl;
  return 0;
}
