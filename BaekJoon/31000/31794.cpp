// Title : 두유노팰린드롬?
// Link  : https://www.acmicpc.net/problem/31794 
// Time  : 104 ms
// Memory: 34432 KB

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
  vector<int64_t> fwd(n + 2), bwd(n + 2), minus(n + 2);
  for (int i = 0; i < table.size(); i++) {
    if (table[i] == 0) continue;
    int sz = table[i], hf = sz >> 1, st = ((i - sz) >> 1) + 1;
    ++fwd[st], --fwd[st + hf];
    ++bwd[st + sz - 1], --bwd[st + hf - 1];
    minus[st] += st - 1, minus[st + hf] -= st - 1;
    minus[st + hf] += n - st - sz + 1, minus[st + sz] -= n - st - sz + 1;
  }

  for (int i = 1; i <= n; i++) fwd[i] += fwd[i - 1];
  for (int i = n; i >= 1; i--) bwd[i] += bwd[i + 1];
  for (int i = 1; i <= n; i++) minus[i] += minus[i - 1];

  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    cout << fwd[x] * x + bwd[x] * (n - x + 1) - minus[x] << "\n";
  }

  return 0;
}