// Title : 팰린드롬 분할
// Link  : https://www.acmicpc.net/problem/1509 
// Time  : 532 ms
// Memory: 14472 KB

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

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
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

    int ri = (i - 1) >> 1;
    if (memo[i] > 1) {
      int b = ri - ((memo[i] - 1) >> 1);
      int e = b + memo[i] - 1;
      while (b < e) pq.push({e--, b++});
    }

    if (i & 1) {
      if (ri > ans[ri]) {
        ans[ri + 1] = ans[ri] + 1;
      } else {
        ans[ri + 1] = ri + 1;
      }

      while (!pq.empty()) {
        auto [e, b] = pq.top();
        if (e != ri) break;
        pq.pop();

        if (ans[ri + 1] > ans[b] + 1) ans[ri + 1] = ans[b] + 1;
      }
    }
  }

  cout << ans[n];

  return 0;
}
