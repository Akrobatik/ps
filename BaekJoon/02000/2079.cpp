// Title : 팰린드롬
// Link  : https://www.acmicpc.net/problem/2079 
// Time  : 0 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

struct Manacher {
  void Init(string_view sv) {
    int n = (sv.size() << 1) + 1;
    table.clear(), table.resize(n);

    string s(n, '\0');
    auto ptr = s.data() + 1;
    for (char c : sv) *ptr = c, ptr += 2;

    int p, r = 0;
    for (int i = 1; i < n - 1; i++) {
      if (i > r) {
        p = r = i;
        while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
        table[i] = --r - p;
      } else {
        if (table[(p << 1) - i] < r - i) {
          table[i] = table[(p << 1) - i];
        } else if (table[(p << 1) - i] > r - i) {
          table[i] = r - i;
        } else {
          p = i;
          while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
          table[i] = --r - p;
        }
      }
    }
  }

  vector<int> table;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  Manacher mnchr;
  mnchr.Init(s);
  auto& table = mnchr.table;

  int n = s.size();
  vector<int> memo(n + 1, n);
  memo[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int len = 1; len <= i; len++) {
      int st = i - len, en = i;
      if (table[st + en] >= len) memo[i] = min<int>(memo[i], memo[i - len] + 1);
    }
  }
  cout << memo[n];

  return 0;
}