// Title : 알 수 없는 문장
// Link  : https://www.acmicpc.net/problem/1099 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

int Calc(const string& s1, const string& s2, int start) {
  if (start < 0 || s1.size() > s2.size() - start) return kInf;

  int c1[26] = {}, c2[26] = {};
  for (int i = 0; i < s1.size(); i++) {
    ++c1[s1[i] - 'a'];
    ++c2[s2[start + i] - 'a'];
  }

  for (int i = 0; i < 26; i++) {
    if (c1[i] == c2[i]) continue;
    return kInf;
  }

  int res = 0;
  for (int i = 0; i < s1.size(); i++) {
    res += (s1[i] != s2[start + i]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n;
  cin >> s >> n;
  vector<string> arr(n);
  for (auto& e : arr) cin >> e;

  int memo[51];
  memo[0] = 0;
  for (int i = 1; i <= s.size(); i++) memo[i] = kInf;

  for (int i = 0; i < s.size(); i++) {
    for (auto& e : arr) {
      int start = i - e.size() + 1, cost = Calc(e, s, start);
      if (cost == kInf) continue;
      memo[i + 1] = min<int>(memo[i + 1], memo[start] + cost);
    }
  }
  int ans = memo[s.size()] != kInf ? memo[s.size()] : -1;
  cout << ans;

  return 0;
}
