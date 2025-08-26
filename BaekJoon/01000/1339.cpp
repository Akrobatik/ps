// Title : 단어 수학
// Link  : https://www.acmicpc.net/problem/1339 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  uint32_t rank[26] = {};

  vector<string> strs(n);
  for (auto& s : strs) {
    cin >> s;
    int sz = s.size();
    for (int i = sz - 1, d = 1; i >= 0; i--, d *= 10) {
      int x = s[i] - 'A';
      rank[x] += d;
    }
  }

  int ids[26];
  iota(ids, ids + 26, 0);
  sort(ids, ids + 26, [&](int lhs, int rhs) {
    return rank[lhs] > rank[rhs];
  });

  char table[128];
  for (int i = 0; i < 26; i++) {
    table[ids[i] + 'A'] = '0' + 9 - i;
  }

  int64_t sum = 0;
  for (auto& s : strs) {
    for (auto& c : s) c = table[c];
    sum += stoi(s);
  }
  cout << sum;

  return 0;
}
