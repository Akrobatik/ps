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

constexpr int kSqrt = 4;
constexpr int kSize = kSqrt * kSqrt;
constexpr int kSqr = kSize * kSize;
constexpr int kCols = 4 * kSize * kSize;
constexpr int kRows = kSize * kSize * kSize;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  DLX dlx;
  dlx.Init(kRows, kCols);
  int board[kSize][kSize];
  int sub_masks[kSize] = {};
  int row_masks[kSize] = {};
  int col_masks[kSize] = {};
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      char c;
      cin >> c;
      board[i][j] = c != '-' ? c - 'A' + 1 : 0;
      if (board[i][j]) {
        int s = i - i % kSqrt + j / kSqrt;
        int m = (1 << (board[i][j] - 1));
        sub_masks[s] |= m;
        row_masks[i] |= m;
        col_masks[j] |= m;
      }
    }
  }

  auto check = [&](int s, int y, int x, int v) {
    int m = 1 << v;
    return board[y][x] == 0 &&
           ((sub_masks[s] & m) == 0) &&
           ((row_masks[y] & m) == 0) &&
           ((col_masks[x] & m) == 0);
  };

  int y = 0, x = 0, v = 0;
  for (int i = 0; i < kRows; i++) {
    int s = y - y % kSqrt + x / kSqrt;
    if (check(s, y, x, v)) {
      int ids[] = {
          y * kSize + x,
          s * kSize + v + kSqr,
          y * kSize + v + kSqr * 2,
          x * kSize + v + kSqr * 3};
      dlx.AddRows(i, ids);
    }

    if (++v == kSize) {
      v = 0;
      if (++x == kSize) {
        x = 0;
        ++y;
      }
    }
  }

  dlx.Search();

  for (auto id : dlx.solution) {
    int y = id / (kSize * kSize);
    int x = (id / kSize) % kSize;
    int v = id % kSize;
    board[y][x] = v + 1;
  }

  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) cout << (char)(board[i][j] + 'A' - 1);
    cout << "\n";
  }

  return 0;
}
