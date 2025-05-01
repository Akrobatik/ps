// Title : 전화번호 목록
// Link  : https://www.acmicpc.net/problem/5052 
// Time  : 24 ms
// Memory: 6680 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : cnt(0), nxt{} {}

  int cnt;
  array<int, 10> nxt;
} nodes[100001];

int nidx;

bool Insert(const string& s) {
  bool fail = false;
  auto node = nodes;
  for (auto c : s) {
    int x = c - '0';
    if (node->nxt[x] == 0) node->nxt[x] = ++nidx;
    node = nodes + node->nxt[x];
    if (node->cnt) fail = true;
  }
  ++node->cnt;
  return fail;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (auto& e : arr) cin >> e;
    sort(arr.begin(), arr.end(), [&](const string& lhs, const string& rhs) {
      return lhs.size() < rhs.size();
    });

    bool fail = false;
    for (auto& e : arr) fail |= Insert(e);
    cout << (fail ? "NO\n" : "YES\n");

    memset(nodes, 0, (nidx + 1) * sizeof(Node));
    nidx = 0;
  }

  return 0;
}
