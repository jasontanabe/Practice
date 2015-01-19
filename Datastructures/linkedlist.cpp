#include <iostream>

struct ListNode {
  ListNode(int data, ListNode* next) : data_(data), next_(next) {}
  ~ListNode() {}
  ListNode* next_;
  int data_;
};

struct List {
  List() : head_(NULL) {}
  ~List() {}
  void push_back(int data) {
    ListNode** node;
    for (node = &head_; *node != NULL; node = &(*node)->next_);
    ListNode* new_node = new ListNode(data, NULL);
    *node = new_node;
  } 
  
  int pop() {
    ListNode* node = head_;
    head_ = head_->next_;
    int data = node->data_;
    delete node;
    return data;
  }

  ListNode* head_;
};

int main() {
  List list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  ListNode* node;
  for (node = list.head_; node != NULL; node = node->next_) {
    std::cout << node->data_ << std::endl;
  }
  while (list.head_ != NULL) {
    std::cout << list.pop() << std::endl;
  }
  return 0;
}
