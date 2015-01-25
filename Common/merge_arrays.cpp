#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<int> merge_arrays(const vector<int>& vec1,
                         const vector<int>& vec2) {
  vector<int> result;
  int index1 = 0;
  int index2 = 0;
  int current;
  // initialize current value
  if (index1 < vec1.size() && index2 < vec2.size()) {
    if (vec1[index1] < vec2[index2]) {
      result.push_back(vec1[index1]);
      current = vec1[index1++];
    } else {
      result.push_back(vec2[index2]);
      current = vec2[index2++];
    }
  }

  // fill in lowest value between two lists and add to result
  // go until one of the vectors is empty
  while (index1 < vec1.size() && index2 < vec2.size()) {
    if (vec1[index1] < vec2[index2]) {
      if (vec1[index1] != current) {
        result.push_back(vec1[index1]);
        current = vec1[index1];
      }
      index1++;
    } else {
      if (vec2[index2] != current) {
        result.push_back(vec2[index2]);
        current = vec2[index2];
      }
      index2++;
    }
  }

  // push the rest of vector 1 to result
  while (index1 < vec1.size()) {
    if (current != vec1[index1]) {
      result.push_back(vec1[index1]);
      current = vec1[index1];
    }
    index1++;
  }

  // push the rest of vector 2 to result
  while (index2 < vec2.size()) {
    if (current != vec2[index2]) {
      result.push_back(vec2[index2]);
      current = vec2[index2];
    }
    index2++;
  }
  return result;
}

int main() {
  vector<int> vec1;
  vector<int> vec2;
  srand(time(0));
  for (int i = 0; i < 10; i++) {
    vec1.push_back(rand()%20);
    vec2.push_back(rand()%20);
  }
  std::cout << "VEC1:" << std::endl;
  for (int i = 0; i < vec1.size(); i++) {
    std::cout << vec1[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "VEC2:" << std::endl;
  for (int i = 0; i < vec2.size(); i++) {
    std::cout << vec2[i] << std::endl;
  }
  std::cout << std::endl;

  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());
  vector<int> merge = merge_arrays(vec1, vec2);
  std::cout << "RESULT:" << std::endl;
  for (int i = 0; i < merge.size(); i++) {
    std::cout << merge[i] << std::endl;
  }
}
