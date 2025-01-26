#include <bits/stdc++.h>

using namespace std;

struct Node {
  int parent;
  vector<pair<int, int>> children;
};

Node nodes[10001];
int memo[10001];

int GetLength(Node* node, int len) {
  int n = node->children.size();
  if (n == 0) {
    return len;
  } else if (n == 1) {
    auto [child_id, child_len] = node->children.front();
    return len + GetLength(nodes + child_id, child_len);
  } else {
    vector<int> vec;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
      auto [child_id, child_len] = node->children[i];
      vec[i] = GetLength(nodes + child_id, child_len);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    memo[distance(nodes, node)] = vec[0] + vec[1];
    return len + vec[0];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    nodes[a].children.push_back(make_pair(b, c));
    nodes[b].parent = a;
  }

  int unary = GetLength(nodes + 1, 0);
  int binary = *max_element(memo + 1, memo + n + 1);
  cout << max<int>(unary, binary) << endl;

  return 0;
}
