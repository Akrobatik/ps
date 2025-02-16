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
bool found;

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

Node* FindColumnById(int id) {
  for (Node* node = root->right; node != root; node = node->right) {
    if (node->id == id) return node;
  }
  return nullptr;
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

    int column_ids[4] = {
        y * kSize + x,
        (y - y % kSizeSqrt + x / kSizeSqrt) * kSize + v + kSizeSqr,
        y * kSize + v + kSizeSqr * 2,
        x * kSize + v + kSizeSqr * 3};

    AddRow(i, cover_nodes, column_ids, column_nodes);
  }
}

void Search() {
  if (root->right == root) {
    found = true;
    return;
  }

  Node* min_node = FindMinColumn();
  if (min_node == nullptr) return;

  CoverColumn(min_node);
  for (auto n1 = min_node->down; !found && n1 != min_node; n1 = n1->down) {
    for (auto n2 = n1->right; n2 != n1; n2 = n2->right) CoverColumn(n2->head);
    Search();
    for (auto n2 = n1->left; n2 != n1; n2 = n2->left) UncoverColumn(n2->head);
  }
  UncoverColumn(min_node);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  BuildMatrix();

  for (int i = 1; i <= kSizeSqr; i++) {
    int y, x, v;
    cin >> y >> x >> v;
    --y, --x, --v;
    int id = y * kSizeSqr + x * kSize + v;
    for (auto& node : cover_nodes[id]) {
      Node* column = node.head;
      if (FindColumnById(column->id) == nullptr) {
        cout << i;
        return 0;
      }
      CoverColumn(column);
    }

    found = false;
    Search();
    if (!found) {
      cout << i;
      return 0;
    }
  }
  cout << -1;

  return 0;
}
