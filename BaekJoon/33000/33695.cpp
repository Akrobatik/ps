// Title : 선물 보내기
// Link  : https://www.acmicpc.net/problem/33695
// Time  : 84 ms
// Memory: 15348 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e9 + 7;

int memo[200001];
vector<int> edges[200001];

int64_t Power(int64_t n, int exp) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = res * n % kMod;
    n = n * n % kMod;
    exp >>= 1;
  }
  return res;
}

void Traverse(int cur) {
  int x = memo[cur], y = x ^ 3;
  for (auto nxt : edges[cur]) {
    if (memo[nxt] == 0) {
      memo[nxt] = y;
      Traverse(nxt);
    }
    if (memo[nxt] == x) {
      cout << "0";
      exit(0);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    if (c == 'D') {
      edges[a].push_back(b);
      edges[b].push_back(a);
      continue;
    }

    int x = 1 + (c & 1), y = x ^ 3;
    if (memo[a] == x || memo[b] == x) {
      cout << "0";
      return 0;
    }
    memo[a] = memo[b] = y;
  }

  for (int i = 1; i <= n; i++) {
    if (edges[i].empty() || memo[i] == 0) continue;
    Traverse(i);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (memo[i]) continue;
    memo[i] = 1;
    Traverse(i);
    ++cnt;
  }
  cout << Power(2, cnt);

  return 0;
}
