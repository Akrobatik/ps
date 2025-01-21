#include <bits/stdc++.h>

using namespace std;

struct Node {
  char id;
  Node* left;
  Node* right;
} nodes[26];

void Preorder(Node* node) {
  cout << node->id;
  if (node->left) Preorder(node->left);
  if (node->right) Preorder(node->right);
}

void Inorder(Node* node) {
  if (node->left) Inorder(node->left);
  cout << node->id;
  if (node->right) Inorder(node->right);
}

void Postorder(Node* node) {
  if (node->left) Postorder(node->left);
  if (node->right) Postorder(node->right);
  cout << node->id;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char a, b, c;
    cin >> a >> b >> c;
    auto& node = nodes[a - 'A'];
    node.id = a;
    node.left = b != '.' ? &nodes[b - 'A'] : nullptr;
    node.right = c != '.' ? &nodes[c - 'A'] : nullptr;
  }

  Preorder(nodes); cout << "\n";
  Inorder(nodes); cout << "\n";
  Postorder(nodes); cout << "\n";

  return 0;
}
