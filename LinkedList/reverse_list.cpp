#include <iostream>

using namespace std;

struct Node {
  Node(int data) : next(NULL), data(data) {}
  int data;
  Node* next;
};

void reverse_list(Node* prev, Node* curr, Node** head) {
  if (curr == NULL) {
    *head = prev;
    return;
  }
  reverse_list(curr, curr->next, head);
  curr->next = prev;
}

int main() {
  Node node0(0), node1(1), node2(2), node3(3);  
  node0.next = &node1;
  node1.next = &node2;
  node2.next = &node3;
  node3.next = NULL;
  Node* node = &node0;
  while (node != NULL) {
    cout << node->data << endl;
    node = node->next;
  }
  cout << endl;
  reverse_list(NULL, &node0, &node);
  while (node != NULL) {
    cout << node->data << endl;
    node = node->next;
  }
  return 0;
}
