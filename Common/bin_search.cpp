#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int bin_search(const vector<int>& vec, int val) {
  int left = 0;
  int right = vec.size()-1;
  int mid;
  while (left <= right) {
    mid = (right - left)/2 + left;
    if (val == vec[mid]) {
      return mid;
    } else if (val < vec[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

int bin_search_r(const vector<int>& vec, int left, int right, int val) {
  if (left > right) {
    return -1;
  }
  int mid = left + (right-left)/2;
  if (val == vec[mid]) {
    return mid;
  } else if (val < vec[mid]) {
    return bin_search_r(vec, left, mid-1, val);
  } else {
    return bin_search_r(vec, mid+1, right, val);
  }
}

int main() {
  vector<int> vec;
  srand(time(0));
  for (int i = 0; i < 10; i++) {
    vec.push_back(rand()%10);
  }
  sort(vec.begin(), vec.end());
  cout << endl << bin_search(vec, 9) << endl;
  cout << bin_search(vec, 9) << endl << endl;
  for (int i = 0; i < 10; i++) {
    cout << vec[i] << endl;
  }
  return 0;
}
