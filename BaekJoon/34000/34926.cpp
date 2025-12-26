// Title : 공룡 게임
// Link  : https://www.acmicpc.net/problem/34926 
// Time  : 8 ms
// Memory: 4148 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<int8_t> memo(n);
  memo[0] = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == '_' && (memo[i - 1] || (i - k >= 0 && memo[i - k]))) {
      memo[i] = 1;
    }
  }
  cout << (memo[n - 1] ? "YES" : "NO");

  return 0;
}