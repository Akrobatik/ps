#include <bits/stdc++.h>

using namespace std;

struct Node {
  bool exist;
  int nxt[26];
};

Node nodes[2501];
int nidx;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end(), [](const string& lhs, const string& rhs) {
    return lhs.size() < rhs.size();
  });

  for (auto& s : vec) {
    Node* node = nodes;
    for (auto c : s) {
      if (!node->nxt[c - 'a']) {
        node->nxt[c - 'a'] = ++nidx;
      }
      node = nodes + node->nxt[c - 'a'];
      if (node->exist) node->exist = false, --n;
    }
    node->exist = true;
  }
  cout << n;

  return 0;
}
