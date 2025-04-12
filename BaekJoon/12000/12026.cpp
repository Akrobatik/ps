// Title : BOJ 거리
// Link  : https://www.acmicpc.net/problem/12026 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  vector<int> b, o, j;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'B') {
      b.push_back(i);
    } else if (s[i - 1] == 'O') {
      o.push_back(i);
    } else {
      j.push_back(i);
    }
  }

  vector<int> memo(n + 1, INT_MAX);
  memo[1] = 0;
  for (int i = 1; i < n; i++) {
    if (memo[i] == INT_MAX) continue;
    if (s[i - 1] == 'B') {
      auto it = upper_bound(o.begin(), o.end(), i);
      while (it != o.end()) {
        auto nxt = *it++;
        memo[nxt] = min<int>(memo[nxt], memo[i] + (nxt - i) * (nxt - i));
      }
    } else if (s[i - 1] == 'O') {
      auto it = upper_bound(j.begin(), j.end(), i);
      while (it != j.end()) {
        auto nxt = *it++;
        memo[nxt] = min<int>(memo[nxt], memo[i] + (nxt - i) * (nxt - i));
      }
    } else {
      auto it = upper_bound(b.begin(), b.end(), i);
      while (it != b.end()) {
        auto nxt = *it++;
        memo[nxt] = min<int>(memo[nxt], memo[i] + (nxt - i) * (nxt - i));
      }
    }
  }
  cout << (memo[n] != INT_MAX ? memo[n] : -1);

  return 0;
}
