// Title : 비숍
// Link  : https://www.acmicpc.net/problem/1799
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int id;
  int size;
  Node *head, *up, *down, *left, *right;
};

Node root;

Node* FindMinColumn() {
  int minn = INT_MAX;
  Node* min_node = nullptr;
  Node* node = root.right;
  while (node != &root) {
    if (node->size > 0 && minn > node->size) {
      minn = node->size;
      min_node = node;
    }
    node = node->right;
  }
  return min_node;
}

void CoverColumn(Node* column) {
  column->left->right = column->right;
  column->right->left = column->left;

  for (Node* row = column->down; row != column; row = row->down) {
    for (Node* node = row->right; node != row; node = node->right) {
      node->up->down = node->down;
      node->down->up = node->up;
      --node->head->size;
    }
  }
}

void UncoverColumn(Node* column) {
  for (Node* row = column->up; row != column; row = row->up) {
    for (Node* node = row->left; node != row; node = node->left) {
      ++node->head->size;
      node->up->down = node;
      node->down->up = node;
    }
  }

  column->left->right = column;
  column->right->left = column;
}

int Search(int depth) {
  auto min_node = FindMinColumn();
  if (min_node == nullptr) return depth;

  int maxx = 0;
  CoverColumn(min_node);
  for (auto n1 = min_node->down; n1 != min_node; n1 = n1->down) {
    for (auto n2 = n1->right; n2 != n1; n2 = n2->right) CoverColumn(n2->head);
    int v = Search(depth + 1);
    maxx = max<int>(maxx, v);
    for (auto n2 = n1->left; n2 != n1; n2 = n2->left) UncoverColumn(n2->head);
  }
  UncoverColumn(min_node);
  return maxx;
}

void Solve(char board[10][10], int n) {
  root.id = -1;
  root.head = root.up = root.down = root.left = root.right = &root;

  int cols = ((n << 1) - 1) << 1;
  vector<Node> nodes;
  nodes.reserve(cols + ((n * n) << 1));
  for (int i = 0; i < cols; i++) {
    nodes.emplace_back();
    auto& node = nodes.back();
    node.id = i;
    node.size = 0;
    node.head = node.up = node.down = &node;
    root.left->right = &node;
    node.left = root.left;
    root.left = &node;
    node.right = &root;
  }
  root.right = &nodes[0];

  int rows = n * n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '0') continue;

      nodes.emplace_back();
      auto& n1 = nodes.back();
      auto c1 = &nodes[i + j];
      if (c1->down == c1) c1->down = &n1;
      ++c1->size;
      c1->up->down = &n1;
      n1.up = c1->up;
      c1->up = &n1;
      n1.down = c1;
      n1.head = c1;

      nodes.emplace_back();
      auto& n2 = nodes.back();
      auto c2 = &nodes[i - j + (n - 1) + ((n << 1) - 1)];
      if (c2->down == c2) c2->down = &n2;
      ++c2->size;
      c2->up->down = &n2;
      n2.up = c2->up;
      c2->up = &n2;
      n2.down = c2;
      n2.head = c2;

      n1.left = n1.right = &n2;
      n2.left = n2.right = &n1;
    }
  }

  cout << Search(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  char board[10][10];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> board[i][j];
  }

  Solve(board, n);

  return 0;
}
