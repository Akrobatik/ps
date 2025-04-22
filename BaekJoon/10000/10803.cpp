// Title : 정사각형 만들기
// Link  : https://www.acmicpc.net/problem/10803 
// Time  : 8 ms
// Memory: 6108 KB

#include <bits/stdc++.h>

using namespace std;

int memo[10001][101];

int Calc(int n, int m) {
  if (n < m) swap(n, m);
  if (n == m) return 1;
  if (memo[n][m]) return memo[n][m];

  int res = INT_MAX;
  if (n / m >= 3) {
    res = min<int>(res, Calc(n - m, m) + 1);
  } else {
    int hn = n >> 1, hm = m >> 1;
    for (int i = 1; i <= hn; i++) {
      res = min<int>(res, Calc(i, m) + Calc(n - i, m));
    }
    for (int i = 1; i <= hm; i++) {
      res = min<int>(res, Calc(n, i) + Calc(n, m - i));
    }
  }
  return memo[n][m] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  cout << Calc(n, m);

  return 0;
}
