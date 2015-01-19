#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(vector<int>& vec, const vector<int>& left, const vector<int>& right);

void merge_sort(vector<int>& vec) {
  if (vec.size() == 1) {
    return;
  }
  vector<int>::iterator mid = vec.begin() + vec.size()/2;
  vector<int> left(vec.begin(), mid);
  vector<int> right(mid, vec.end());
  merge_sort(left);
  merge_sort(right);
  merge(vec, left, right);
}

void merge(vector<int>& vec, const vector<int>& left, 
           const vector<int>& right) {
  int left_pos = 0;
  int right_pos = 0;
  vector<int> result;
  while (left_pos < left.size() && right_pos < right.size()) {
    if (left[left_pos] < right[right_pos]) {
      result.push_back(left[left_pos++]);
    } else {
      result.push_back(right[right_pos++]);
    }
  }
  while (left_pos < left.size()) {
    result.push_back(left[left_pos++]);
  }
  while (right_pos < right.size()) {
    result.push_back(right[right_pos++]);
  }
  vec = result;
}

int main() {
  vector<int> vec;
  srand(time(0));
  for (int i = 0; i < 1000; i++) {
    vec.push_back(rand()%100);
  }
  merge_sort(vec);
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << std::endl;
  }
  return 0;
}
