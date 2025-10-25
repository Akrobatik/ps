// Title : Generate Optimal Key
// Link  : https://www.acmicpc.net/problem/33266 
// Time  : 20 ms
// Memory: 9848 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1000;

struct Node {
  Node() : nxt{} {}

  int nxt[2];
};

int ans, nidx;
int val[kMax + 1][2], bwd[kMax + 2];
Node nodes[kMax * kMax + 1];

void Insert(const string& s) {
  Node* node = nodes;
  for (auto c : s) {
    int x = c - '0';
    if (node->nxt[x] == 0) node->nxt[x] = ++nidx;
    node = nodes + node->nxt[x];
  }
}

void Calc(int nd, int idx, int len, int sum) {
  if (idx > len) return;
  for (int b = 0; b < 2; b++) {
    int snxt = sum + val[idx][b ^ 1];
    int nnxt = nodes[nd].nxt[b];
    if (nnxt) {
      Calc(nnxt, idx + 1, len, snxt);
    } else {
      ans = min<int>(ans, snxt + bwd[idx + 1]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, l;
  cin >> n >> m >> l;

  while (n--) {
    string s;
    cin >> s;
    for (int i = 0; i < l; i++) {
      ++val[i + 1][s[i] - '0'];
    }
  }

  for (int i = l; i >= 1; i--) {
    bwd[i] = bwd[i + 1] + min<int>(val[i][0], val[i][1]);
  }

  while (m--) {
    string s;
    cin >> s;
    Insert(s);
  }

  ans = INT_MAX;
  Calc(0, 1, l, 0);
  cout << ans;

  return 0;
}