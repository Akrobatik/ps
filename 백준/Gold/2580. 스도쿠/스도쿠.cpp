#include <bits/stdc++.h>

using namespace std;

constexpr int kSizeSqrt = 3;
constexpr int kSize = kSizeSqrt * kSizeSqrt;
constexpr int kSizeSqr = kSize * kSize;
constexpr int kCols = 4 * kSize * kSize;
constexpr int kRows = kSize * kSize * kSize;

struct Node {
  int id;
  int size;
  Node *head, *up, *down, *left, *right;
};

Node root;
int board[kSize][kSize];
int column_remains;
vector<int> pick;

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
  --column_remains;

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
  ++column_remains;

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

void AddRow(int row_id, vector<vector<Node>>& nodes, const vector<int>& column_ids, vector<Node>& column_nodes) {
  int size = column_ids.size();
  if (size == 0) return;

  auto& row_nodes = nodes.emplace_back();
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
    row_nodes[i].right = &row_nodes[(i + 1) % size];
    row_nodes[i].left = &row_nodes[(i + size - 1) % size];
  }
}

void Search() {
  if (column_remains == 0) return;

  auto min_node = FindMinColumn();
  if (min_node == nullptr) return;

  CoverColumn(min_node);
  for (auto n1 = min_node->down; n1 != min_node; n1 = n1->down) {
    pick.push_back(n1->id);
    for (auto n2 = n1->right; n2 != n1; n2 = n2->right) CoverColumn(n2->head);
    Search();
    if (column_remains == 0) return;
    pick.pop_back();
    for (auto n2 = n1->left; n2 != n1; n2 = n2->left) UncoverColumn(n2->head);
  }
  UncoverColumn(min_node);
}

void Solve() {
  root.id = -1;
  root.head = root.up = root.down = root.left = root.right = &root;

  vector<Node> column_nodes;
  column_nodes.reserve(kCols);
  for (int i = 0; i < kCols; i++) {
    Node* node = &column_nodes.emplace_back();
    node->id = i;
    node->size = 0;
    node->head = node->up = node->down = node;
    root.left->right = node;
    node->left = root.left;
    root.left = node;
    node->right = &root;
  }
  root.right = &column_nodes[0];

  auto check = [&](int y, int x, int gy, int gx, int v) {
    if (board[y][x]) return false;

    for (int i = 0; i < kSizeSqrt; i++) {
      for (int j = 0; j < kSizeSqrt; j++) {
        if (board[gy + i][gx + j] == v + 1) return false;
      }
    }

    for (int i = 0; i < kSize; i++) {
      if (board[y][i] == v + 1) return false;
    }

    for (int i = 0; i < kSize; i++) {
      if (board[i][x] == v + 1) return false;
    }

    return true;
  };

  vector<int> column_ids(4);
  vector<vector<Node>> nodes;
  nodes.reserve(kRows);
  for (int i = 0; i < kRows; i++) {
    int y = i / (kSize * kSize);
    int x = (i / kSize) % kSize;
    int v = i % kSize;
    int gy = y - y % kSizeSqrt;
    int gx = x - x % kSizeSqrt;

    if (!check(y, x, gy, gx, v)) continue;

    column_ids[0] = y * kSize + x;
    column_ids[1] = ((gy + gx / kSizeSqrt) * kSize + v) + kSizeSqr;
    column_ids[2] = (y * kSize + v) + kSizeSqr * 2;
    column_ids[3] = (x * kSize + v) + kSizeSqr * 3;
    AddRow(i, nodes, column_ids, column_nodes);
  }

  for (auto& node : column_nodes) column_remains += (node.size != 0);
  pick.reserve(kSizeSqr);

  Search();

  for (auto id : pick) {
    int y = id / (kSize * kSize);
    int x = (id / kSize) % kSize;
    int v = id % kSize;
    board[y][x] = v + 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) cin >> board[i][j];
  }
  Solve();
  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) cout << board[i][j] << " ";
    cout << "\n";
  }

  return 0;
}
