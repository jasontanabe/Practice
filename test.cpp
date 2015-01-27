#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
  queue<int> q_vals;
  q_vals.push(1);
  q_vals.push(2);
  q_vals.push(3);
  q_vals.push(4);
  q_vals.push(5);
  while (!q_vals.empty()) {
    cout << q_vals.front() << endl;
    q_vals.pop();
  }
  cout << endl;

  stack<int> s_vals;
  s_vals.push(1);
  s_vals.push(2);
  s_vals.push(3);
  s_vals.push(4);
  s_vals.push(5);
  while (!s_vals.empty()) {
    cout << s_vals.top() << endl;
    s_vals.pop();
  }
  cout << endl;

  unordered_map<string, int> dict;
  dict["jason"] = 1;
  dict["tanabe"] = 2;
  unordered_map<string, int>::iterator it = dict.find("jason");
  if (it != dict.end()) {
    cout << "looking for jason ";
    cout << (*it).second << endl;
  }
  dict["test"] = 3;
  for (unordered_map<string, int>::const_iterator it = dict.begin();
       it != dict.end(); it++) {
    cout << (*it).first << ", " << (*it).second << endl;
  }
  return 0;
}
