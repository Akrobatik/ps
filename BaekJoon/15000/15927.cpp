// Title : 회문은 회문아니야!!
// Link  : https://www.acmicpc.net/problem/15927 
// Time  : 16 ms
// Memory: 8520 KB

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

  int n = s.size();

  Manacher mnchr;
  mnchr.Init(s);

  vector<int> cnt(n + 1);

  auto& table = mnchr.table;
  for (auto e : table) ++cnt[e];

  for (int i = n; i >= 3; i -= 2) {
    cnt[i - 2] += cnt[i];
    cnt[i - 3] += cnt[i - 1];
  }

  int ans = -1;
  for (int i = n; i >= 1; i--) {
    if (cnt[i] == n - i + 1) continue;
    ans = i;
    break;
  }
  cout << ans;

  return 0;
}
