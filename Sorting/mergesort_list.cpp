#include <iostream>

using namespace std;

struct Node {
  Node(int data, Node* next) : data(data), next(next) {}
  Node* next;
  int data;
};

Node* merge(Node* left, Node* right) {
  Node* result;
  Node** n = &result;
  while (left && right) {
    if (left->data < right->data) {
      *n = left;
      left = left->next;
    } else {
      *n = right;
      right = right->next;
    }
    n = &(*n)->next;
  }
  if (left) {
    *n = left;
  } else if (right) {
    *n = right;
  }
  return result;
}

Node* split(Node* in) {
  if (!in) {
    return NULL;
  }

  Node* half = in;
  while (in) {
    in = in->next;
    if (!in || !in->next) {
      break;
    }
    half = half->next;
    in = in->next;
  }
  Node* rest = half->next;
  half->next = NULL;
  return rest;
}

Node* mergesort(Node* list) {
  if (list == NULL || list->next == NULL) {
    return list;
  }
  Node* left = list;
  Node* right = split(left);
  left = mergesort(left);
  right = mergesort(right);
  return merge(left, right);
}

int main() {
  Node one(1, NULL), two(2, NULL), three(3, NULL),
       four(4, NULL), five(5, NULL);
  five.next = &four;
  four.next = &three;
  three.next = &two;
  two.next = &one;
  Node* node = &five;
  while (node != NULL) {
    cout << node->data << endl;
    node = node->next;
  }
  cout << endl;

  node = mergesort(&five);
  while (node != NULL) {
    cout << node->data << endl;
    node = node->next;
  }

  return 0;
}
