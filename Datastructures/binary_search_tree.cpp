#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node {
  Node(int data) : data(data), left(NULL), right(NULL) {}
  Node* left;
  Node* right;
  int data;
};

void swap(int& one, int& two) {
  int temp = one;
  one = two;
  two = temp;
}

void add(Node** root, int data) {
  if (*root == NULL) {
    *root = new Node(data);
    return;
  }

  if (data < (*root)->data) {
    add(&(*root)->left, data);
  } else {
    add(&(*root)->right, data);
  }
}

Node** find(Node** root, int data) {
  if (*root == NULL) {
    return NULL;
  }
  if ((*root)->data == data) {
    return root;
  } else if (data < (*root)->data) {
    return find(&(*root)->left, data);
  } else {
    return find(&(*root)->right, data);
  }
}

Node** findMax(Node** root) {
  if (*root == NULL) {
    return NULL;
  }
  if ((*root)->right == NULL) {
    return root;
  }
  findMax(&(*root)->right);
}

void remove_mid_node(Node** node, Node* swap_node) {
  Node* temp = *node;
  *node = swap_node;
  delete temp;
}

void remove(Node** root, int data) {
  Node** delete_node = find(root, data);
  if (delete_node == NULL) {
    return;
  }
  if ((*delete_node)->left && (*delete_node)->right) {
    Node** sub_max = findMax(&(*delete_node)->left);
    swap((*sub_max)->data, (*delete_node)->data);
    if ((*sub_max)->left) {
      remove_mid_node(sub_max, (*sub_max)->left);
    } else {
      delete *sub_max;
      *sub_max = NULL;
    }
  } else if ((*delete_node)->left) {
    remove_mid_node(delete_node, (*delete_node)->left);
  } else if ((*delete_node)->right) {
    remove_mid_node(delete_node, (*delete_node)->right);
  } else {
    delete *delete_node;
    *delete_node = NULL;
  }
}

void inorder(Node* root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << endl;
  inorder(root->right);
}

void postorder(Node* root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << endl;
}

void preorder(Node* root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << endl;
  preorder(root->left);
  preorder(root->right);
}

int main() {
  Node* root = NULL;
  srand(time(0));
  add(&root, 8);
  add(&root, 10);
  add(&root, 14);
  add(&root, 13);
  add(&root, 3);
  add(&root, 6);
  add(&root, 7);
  add(&root, 4);
  add(&root, 1);
  remove(&root, 8);
  remove(&root, 1);
  remove(&root, 3);
  remove(&root, 10);
  remove(&root, 14);
  remove(&root, 7);
  remove(&root, 4);
  remove(&root, 6);
  remove(&root, 13);
  inorder(root);
  cout << endl;
  /*
  postorder(root);
  cout << endl;
  preorder(root);
  */
  return 0;
}
