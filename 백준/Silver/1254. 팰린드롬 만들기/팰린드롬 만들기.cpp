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

  char s[51];
  cin >> s;
  Manacher mncher;
  mncher.Init(s);
  int nm = mncher.table.size() - 1;
  int n = nm >> 1;

  int maxx;
  for (int i = 1; i <= n; i++) {
    if (mncher.table[nm - i] == i) maxx = i;
  }
  cout << nm - maxx;

  return 0;
}
