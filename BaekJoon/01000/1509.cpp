// Title : 팰린드롬 분할
// Link  : https://www.acmicpc.net/problem/1509
// Time  : 8 ms
// Memory: 2056 KB

#include <bits/stdc++.h>

using namespace std;

char s[5002];
int memo[5001];
int ans[2501];

bool IsPalindrom(int i, int j) {
  return j - i < memo[i + j + 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char c;
  int n = 0;
  while (cin >> c) s[(n++ << 1) + 1] = c;

  int p, r = 0;
  int nn = n * 2 + 1;
  for (int i = 1; i < nn - 1; i++) {
    if (i > r) {
      p = r = i;
      while (r < nn && r <= p * 2 && s[r] == s[p * 2 - r]) ++r;
      memo[i] = --r - p;
    } else {
      if (memo[p * 2 - i] < r - i) {
        memo[i] = memo[p * 2 - i];
      } else if (memo[p * 2 - i] > r - i) {
        memo[i] = r - i;
      } else {
        p = i;
        while (r < nn && r <= p * 2 && s[r] == s[p * 2 - r]) ++r;
        memo[i] = --r - p;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    ans[i + 1] = i + 1;
    for (int j = 0; j <= i; j++) {
      if (IsPalindrom(j, i) && ans[i + 1] > ans[j] + 1) {
        ans[i + 1] = ans[j] + 1;
      }
    }
  }

  cout << ans[n];

  return 0;
}
