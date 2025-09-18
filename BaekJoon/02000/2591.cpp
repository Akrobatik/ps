// Title : 숫자카드
// Link  : https://www.acmicpc.net/problem/2591 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  for (auto& c : s) c -= '0';
  int n = s.size();

  vector<int64_t> memo(n + 1);
  memo[0] = 1;
  for (int i = 0; i < n; i++) {
    if (s[i]) memo[i + 1] = memo[i];
    if (i && s[i - 1] && s[i - 1] * 10 + s[i] <= 34) memo[i + 1] += memo[i - 1];
  }
  cout << memo[n];

  return 0;
}