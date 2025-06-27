// Title : 장난감 섞기
// Link  : https://www.acmicpc.net/problem/25608 
// Time  : 88 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : Node(0) {}
  Node(int v) : val(v), sum(v), fwd(v), bwd(v) {}

  friend Node operator+(const Node& lhs, const Node& rhs) {
    Node res;
    res.val = max<int>({lhs.val, rhs.val, lhs.bwd + rhs.fwd});
    res.sum = lhs.sum + rhs.sum;
    res.fwd = max<int>(lhs.fwd, lhs.sum + rhs.fwd);
    res.bwd = max<int>(rhs.bwd, rhs.sum + lhs.bwd);
    return res;
  }

  int val, sum, fwd, bwd;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<Node> arr(n);
  for (int i = 0; i < n; i++) {
    Node node;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      node = node + Node(x);
    }
    arr[i] = node;
  }

  vector<int> cands(n);
  iota(cands.begin(), cands.end(), 0);

  int maxx = 0;
  do {
    Node node;
    for (auto e : cands) {
      node = node + arr[e];
    }
    maxx = max<int>(maxx, node.val);
  } while (next_permutation(cands.begin(), cands.end()));

  cout << maxx;

  return 0;
}
