#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int left_child(int index) {
  return 2*index + 1;
}

int right_child(int index) {
  return 2*index + 2;
}

int parent(int index) {
  return (index - 1)/2;
}

void swap(int& one, int& two) {
  int temp = one;
  one = two;
  two = temp;
}

void percolate_up(vector<int>& vec, int index) {
  int parent_index = parent(index);
  while (parent_index > 0) {
    if (vec[index] < vec[parent_index]) {
      swap(vec[index], vec[parent_index]);
    } else {
      break;
    }
    index = parent_index;
    parent_index = parent(index);
  }
}

void percolate_down(vector<int>& vec, int index) {
  int smallest_child;
  int left = left_child(index);
  int right = right_child(index);
  while (left < vec.size()) {
    smallest_child = left;
    if (right < vec.size()) {
      if (vec[left] > vec[right]) {
        smallest_child = right;
      }
    }
    if (vec[index] > vec[smallest_child]) {
      swap(vec[index], vec[smallest_child]);
    } else {
      break;
    }
    index = smallest_child;
    left = left_child(index);
    right = right_child(index);
  }
}

void heapify(vector<int>& vec) {
  for (int i = vec.size()-1; i >= 0; i--) {
    percolate_down(vec, i);
  }
}

void in_order(const vector<int>& vec, int index) {
  if (index >= vec.size()) {
    return;
  }
  in_order(vec, left_child(index));
  std::cout << vec[index] << std::endl;
  in_order(vec, right_child(index));
}

int pop(vector<int>& vec) {
  int val = vec[0];
  swap(vec[0], vec[vec.size()-1]);
  vec.pop_back();
  percolate_down(vec, 0);
  return val;
}

void insert(vector<int>& vec, int val) {
  vec.push_back(val);
  percolate_up(vec, vec.size()-1);
}

int main() {
  vector<int> vec;
  srand(time(0));
  for (int i = 0; i < 10; i++) {
    vec.push_back(rand()%100);
  }
  heapify(vec);
  for (int i = 0; i < 10; i++) {
    insert(vec, rand()%100);
  }
  while (vec.size() > 0) {
    std::cout << pop(vec) << std::endl;    
  }
  return 0;
}
