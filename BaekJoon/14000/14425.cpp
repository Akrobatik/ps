// Title : 문자열 집합
// Link  : https://www.acmicpc.net/problem/14425 
// Time  : 496 ms
// Memory: 529368 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : ext(0), nxt{} {}

  int ext;
  int nxt[26];
} nodes[10000 * 500 + 1];

int idx;

void Insert(const string& s) {
  auto node = nodes;
  for (auto c : s) {
    int x = c - 'a';
    if (node->nxt[x] == 0) node->nxt[x] = ++idx;
    node = nodes + node->nxt[x];
  }
  node->ext = 1;
}

int Query(const string& s) {
  auto node = nodes;
  for (auto c : s) {
    int x = c - 'a';
    if (node->nxt[x] == 0) return 0;
    node = nodes + node->nxt[x];
  }
  return node->ext;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n, m;
  cin >> n >> m;
  while (n--) {
    cin >> s;
    Insert(s);
  }
  int cnt = 0;
  while (m--) {
    cin >> s;
    cnt += Query(s);
  }
  cout << cnt;

  return 0;
}
