// Title : 문자열 판별
// Link  : https://www.acmicpc.net/problem/16500 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n;
  cin >> s >> n;

  vector<string> strs(n);
  for (auto& str : strs) cin >> str;

  int ns = s.size();

  auto Match = [&](int p, int idx) -> int {
    auto& str = strs[idx];
    int rem = ns - p;
    if (rem < str.size()) return 0;

    bool ok = true;
    for (int i = 0; ok && i < str.size(); i++) {
      ok = (s[p + i] == str[i]);
    }
    return ok ? str.size() : 0;
  };

  vector<bool> memo(ns + 1);
  memo[0] = true;

  for (int i = 0; i < ns; i++) {
    if (!memo[i]) continue;
    for (int j = 0; j < n; j++) {
      auto x = Match(i, j);
      if (x > 0) memo[i + x] = true;
    }
  }

  cout << memo[ns];

  return 0;
}