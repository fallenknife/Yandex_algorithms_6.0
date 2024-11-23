#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
  int data;
  int depth;  // Added depth field
  Node *left, *right;
  Node(int data, int depth = 0)
      : data(data), depth(depth), left(nullptr), right(nullptr) {}
};

Node* Insert(Node* root, int data, int depth) {
  if (root == nullptr) {
    return new Node(data, depth);
  }
  if (data < root->data) {
    root->left = Insert(root->left, data, depth + 1);
  } else if (data > root->data) {
    root->right = Insert(root->right, data, depth + 1);
  }
  return root;
}

bool Search(Node* root, int data) {
  if (root == nullptr) {
    return false;
  }
  if (data == root->data) {
    return true;
  }
  if (data < root->data) {
    return Search(root->left, data);
  } else {
    return Search(root->right, data);
  }
}

void PrintTree(Node* root) {
  if (root == nullptr) return;
  PrintTree(root->left);
  for (int i = 0; i < root->depth; ++i) {
    cout << ".";
  }
  cout << root->data << endl;
  PrintTree(root->right);
}

int main() {
  Node* root = nullptr;
  string task;

  while (cin >> task) {
    if (task == "ADD") {
      int element;
      cin >> element;
      if (!Search(root, element)) {
        root = Insert(root, element, 0);
        cout << "DONE" << endl;
      } else {
        cout << "ALREADY" << endl;
      }
    } else if (task == "SEARCH") {
      int element;
      cin >> element;
      if (Search(root, element)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (task == "PRINTTREE") {
      PrintTree(root);
    }
  }
  return 0;
}
