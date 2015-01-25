#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string one = "hellothere";
  string two = "therehelloa";
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  if (one == two) {
    cout << "anagrams" << endl;
  } else {
    cout << "not anagrams" << endl;
  }
}
