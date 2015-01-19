#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void swap(int& one, int& two) {
  int temp = one;
  one = two;
  two = temp;
}

void quicksort(vector<int>& vec, int left, int right) {
  int l = left;
  int r = right - 1;
  int size = right - left;
  if (size > 1) {
    int pivot = vec[rand() % size + l];
    while (l < r) {
      while (vec[r] > pivot && r > l) {
        r--;
      }
      while (vec[l] < pivot && l <= r) {
        l++;
      }
      if (l < r) {
        swap(vec[l], vec[r]);
        l++;
      }
    }
    quicksort(vec, left, l);
    quicksort(vec, r, right);
  }
}

int partition(vector<int>& vec, int left, int right) {
  int pivot_index = left + rand() % (right-left+1);
  int pivot = vec[pivot_index];
  swap(vec[pivot_index], vec[right]);
  pivot_index = right;
  int i = left;
  for (int j = left; j < right; j++) {
    if (vec[j] < pivot) {
      swap(vec[i], vec[j]);
      i++;
    }
  }
  swap(vec[i], vec[pivot_index]);
  return i;
}

void quicksort2(vector<int>& vec, int left, int right) {
  if (left < right) {
    int mid = partition(vec, left, right);
    quicksort2(vec, left, mid-1);
    quicksort2(vec, mid+1, right);
  }
}

int main() {
  srand(time(0));
  vector<int> vec;
  for (int i = 0; i < 100; i++) {
    vec.push_back(rand()%100);
  }
  quicksort2(vec, 0, vec.size()-1);
  int val = -1;
  for (int i = 0; i < 100; i++) {
    if (val > vec[i]) {
      std::cout << "WRONG" << std::endl;
    }
    val = vec[i];
    cout << vec[i] << endl;
  }
  return 0;
}

