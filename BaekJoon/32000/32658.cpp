// Title : 오장원전
// Link  : https://www.acmicpc.net/problem/32658 
// Time  : 208 ms
// Memory: 25540 KB

#include <bits/stdc++.h>

using namespace std;

int64_t memo[301][10001];

int64_t Calc(int x, int k, int l) {
  return max<int64_t>(memo[k - 1][x], memo[k][x - l]) + l;
}

int64_t GetMin(int x, int k) {
  int l = 1, r = x + 1;
  while (l + 2 < r) {
    int ll = (l + l + r) / 3;
    int rr = (l + r + r) / 3;
    if (Calc(x, k, ll) < Calc(x, k, rr)) {
      r = rr;
    } else {
      l = ll;
    }
  }

  int64_t minn = INT64_MAX;
  for (int i = l; i < r; i++) {
    minn = min<int64_t>(minn, Calc(x, k, i));
  }
  return minn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, k, c;
  cin >> x >> k >> c;

  for (int i = 1; i <= x; i++) {
    memo[0][i] = i + c;
  }

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= x; j++) {
      memo[i][j] = GetMin(j, i) + c;
    }
  }
  cout << memo[k][x];

  return 0;
}
