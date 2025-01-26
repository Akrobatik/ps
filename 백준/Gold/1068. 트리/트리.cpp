#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : parent(nullptr), children() {}

  Node* parent;
  vector<Node*> children;
};

Node nodes[50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    if (m == -1) {
      nodes[i].parent = nullptr;
    } else {
      nodes[i].parent = &nodes[m];
      nodes[m].children.push_back(&nodes[i]);
    }
  }

  int k;
  cin >> k;
  auto* prune = &nodes[k];
  if (prune->parent) {
    auto& pc = prune->parent->children;
    auto it = find(pc.begin(), pc.end(), prune);
    pc.erase(it);
    prune->parent = nullptr;
  }

  int result = 0;

  queue<Node*> q;
  for (int i = 0; i < n; i++) {
    if (nodes[i].parent == nullptr && i != k) q.push(&nodes[i]);
  }

  while (!q.empty()) {
    auto* node = q.front();
    q.pop();

    if (node->children.empty()) result++;
    for (auto child : node->children) q.push(child);
  }

  cout << result << endl;

  return 0;
}