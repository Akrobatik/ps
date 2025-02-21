#include <bits/stdc++.h>

using namespace std;

struct DLX {
  struct Node {
    int id;
    int size;
    Node *head, *up, *down, *left, *right;
  };

  DLX() : root(new Node()) {}
  ~DLX() { delete root; }

  void Init(int rows, int cols) {
    column_nodes.clear(), column_nodes.resize(cols);
    cover_nodes.clear(), cover_nodes.resize(rows);
    solution.clear();

    root->right = &column_nodes.front();
    root->left = &column_nodes.back();
    for (int i = 0; i < cols; i++) {
      column_nodes[i].id = i;
      column_nodes[i].size = 0;
      column_nodes[i].head = &column_nodes[i];
      column_nodes[i].up = column_nodes[i].down = &column_nodes[i];

      column_nodes[i].left = i == 0 ? root : &column_nodes[i - 1];
      column_nodes[i].right = i == cols - 1 ? root : &column_nodes[i + 1];
    }
  }

  void AddRows(int row_id, span<int> column_ids) {
    int size = column_ids.size();
    if (!size) return;

    auto& row_nodes = cover_nodes[row_id];
    row_nodes.reserve(size);
    for (int column_id : column_ids) {
      Node* column_node = &column_nodes[column_id];
      Node* node = &row_nodes.emplace_back();
      if (column_node->down == column_node) column_node->down = node;
      ++column_node->size;
      node->id = row_id;
      column_node->up->down = node;
      node->up = column_node->up;
      column_node->up = node;
      node->head = node->down = column_node;
    }

    for (int i = 0; i < size; i++) {
      int l = (i + size - 1) % size;
      int r = (i + 1) % size;
      row_nodes[i].left = &row_nodes[l];
      row_nodes[i].right = &row_nodes[r];
    }
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

  Node* FindMinColumn() {
    Node* min_node = root->right;
    int minn = min_node->size;
    for (Node* node = min_node->right; node != root; node = node->right) {
      if (minn > node->size) min_node = node, minn = node->size;
    }
    return min_node;
  }

  bool Search() {
    for (auto& node : column_nodes) {
      if (node.size) continue;
      node.left->right = node.right;
      node.right->left = node.left;
    }
    return _Search();
  }

  bool _Search() {
    if (root->right == root) return true;
    Node* min_node = FindMinColumn();
    CoverColumn(min_node);
    for (Node* row = min_node->down; row != min_node; row = row->down) {
      solution.push_back(row->id);
      for (Node* node = row->right; node != row; node = node->right) CoverColumn(node->head);
      if (_Search()) return true;
      for (Node* node = row->left; node != row; node = node->left) UncoverColumn(node->head);
      solution.pop_back();
    }
    UncoverColumn(min_node);
    return false;
  }

  Node* root;
  vector<Node> column_nodes;
  vector<vector<Node>> cover_nodes;
  vector<int> solution;
};
