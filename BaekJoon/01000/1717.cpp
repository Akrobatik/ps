// Title : 집합의 표현
// Link  : https://www.acmicpc.net/problem/1717 
// Time  : 32 ms
// Memory: 9832 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1000001], sz[1000001];

int Find(int id) {
  while (memo[id] != id) {
    int par = memo[id];
    id = memo[id] = memo[par];
  }
  return id;
}

void Union(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  memo[b] = a;
  sz[a] += sz[b];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) memo[i] = i, sz[i] = 1;

  while (m--) {
    char cmd;
    int a, b;
    cin >> cmd >> a >> b;
    if (cmd == '0') {
      Union(a, b);
    } else {
      cout << (Find(a) == Find(b) ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
