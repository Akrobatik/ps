// Title : 휴대폰 자판
// Link  : https://www.acmicpc.net/problem/5670
// Time  : 188 ms
// Memory: 96076 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5 * 80;

struct Node {
  Node() : exist(false), cnt(0), nxt{} {}

  bool exist;
  int cnt;
  int nxt[26];
};

char s[100000][81];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout.precision(2);
  vector<Node> nodes;

  int n;
  while (cin >> n) {
    nodes.clear(), nodes.emplace_back();
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      Node* node = nodes.data();
      for (auto ptr = s[i]; *ptr; ++ptr) {
        int x = *ptr - 'a';
        if (node->nxt[x] == 0) {
          ++node->cnt;
          node->nxt[x] = nodes.size();
          node = &nodes.emplace_back();
        } else {
          node = nodes.data() + node->nxt[x];
        }
      }
      node->exist = true;
    }

    int sum = n;
    auto root = nodes.data();
    for (int i = 0; i < n; i++) {
      Node* node = root + root->nxt[s[i][0] - 'a'];
      for (auto ptr = s[i] + 1; *ptr; ++ptr) {
        sum += (node->cnt != 1 || node->exist);
        int x = *ptr - 'a';
        node = root + node->nxt[x];
      }
    }
    sum *= 100;
    sum = sum / n + (sum % n >= ((n + (n & 1))) >> 1);
    cout << fixed << (double)sum / 100.0 << "\n";
  }

  return 0;
}
