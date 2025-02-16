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

int board[kSize][kSize];
Node* root = new Node();
vector<Node> column_nodes(kCols);
vector<vector<Node>> cover_nodes;
int sub_masks[kSize];
int row_masks[kSize];
int col_masks[kSize];
int column_remains;
int ans[kSizeSqr];
int* ans_it = ans;

Node* FindMinColumn() {
  int minn = INT_MAX;
  Node* min_node = nullptr;
  Node* node = root->right;
  while (node != root) {
    if (minn > node->size) {
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
  for (Node* row = column->up; row != column; row = row->up) {
    for (Node* node = row->left; node != row; node = node->left) {
      ++node->head->size;
      node->up->down = node;
      node->down->up = node;
    }
  }

  ++column_remains;
  column->left->right = column;
  column->right->left = column;
}

bool IsValid(int y, int x, int v) {
  int s = y - y % kSizeSqrt + x / kSizeSqrt;
  int m = 1 << v;
  return board[y][x] == 0 &&
         ((sub_masks[s] & m) == 0) &&
         ((row_masks[y] & m) == 0) &&
         ((col_masks[x] & m) == 0);
}

void AddRow(int row_id, vector<vector<Node>>& cover_nodes, int column_ids[4], vector<Node>& column_nodes) {
  auto& row_nodes = cover_nodes.emplace_back();
  row_nodes.reserve(4);
  for (int i = 0; i < 4; i++) {
    int column_id = column_ids[i];
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

  constexpr int kLIdx[] = {3, 0, 1, 2};
  constexpr int kRIdx[] = {1, 2, 3, 0};
  for (int i = 0; i < 4; i++) {
    row_nodes[i].left = &row_nodes[kLIdx[i]];
    row_nodes[i].right = &row_nodes[kRIdx[i]];
  }
}

void BuildMatrix() {
  root->right = &column_nodes[0];
  root->left = &column_nodes[kCols - 1];
  for (int i = 0; i < kCols; i++) {
    column_nodes[i].id = i;
    column_nodes[i].size = 0;
    column_nodes[i].head = &column_nodes[i];
    column_nodes[i].up = column_nodes[i].down = &column_nodes[i];

    column_nodes[i].left = (i == 0) ? root : &column_nodes[i - 1];
    column_nodes[i].right = (i == kCols - 1) ? root : &column_nodes[i + 1];
  }

  cover_nodes.reserve(kRows);
  for (int i = 0; i < kRows; i++) {
    int y = i / (kSize * kSize);
    int x = (i / kSize) % kSize;
    int v = i % kSize;
    if (!IsValid(y, x, v)) continue;

    int column_ids[4] = {
        y * kSize + x,
        (y - y % kSizeSqrt + x / kSizeSqrt) * kSize + v + kSizeSqr,
        y * kSize + v + kSizeSqr * 2,
        x * kSize + v + kSizeSqr * 3};

    AddRow(i, cover_nodes, column_ids, column_nodes);
  }

  for (auto& node : column_nodes) {
    if (node.size == 0) {
      node.left->right = node.right;
      node.right->left = node.left;
    } else {
      ++column_remains;
    }
  }
}

void ApplyToBoard() {
  for (auto it = ans; it != ans_it; ++it) {
    int id = *it;
    int y = id / (kSize * kSize);
    int x = (id / kSize) % kSize;
    int v = id % kSize;
    board[y][x] = v + 1;
  }
}

void Search() {
  if (column_remains == 0) return;

  Node* min_node = FindMinColumn();
  if (min_node == nullptr) return;

  CoverColumn(min_node);
  for (auto n1 = min_node->down; n1 != min_node; n1 = n1->down) {
    *ans_it++ = n1->id;
    for (auto n2 = n1->right; n2 != n1; n2 = n2->right) CoverColumn(n2->head);
    Search();
    if (column_remains == 0) return;
    --ans_it;
    for (auto n2 = n1->left; n2 != n1; n2 = n2->left) UncoverColumn(n2->head);
  }
  UncoverColumn(min_node);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) {
      cin >> board[i][j];
      if (board[i][j]) {
        int s = i - i % kSizeSqrt + j / kSizeSqrt;
        int m = (1 << (board[i][j] - 1));
        sub_masks[s] |= m;
        row_masks[i] |= m;
        col_masks[j] |= m;
      }
    }
  }

  BuildMatrix();
  Search();
  ApplyToBoard();

  for (int i = 0; i < kSize; i++) {
    for (int j = 0; j < kSize; j++) cout << board[i][j] << " ";
    cout << "\n";
  }

  return 0;
}
