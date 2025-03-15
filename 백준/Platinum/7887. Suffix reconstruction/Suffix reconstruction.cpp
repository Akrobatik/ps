#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> sa, ranks;
  string s;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    sa.resize(n), ranks.resize(n + 1);
    s.resize(n);
    for (auto& e : sa) cin >> e, --e;
    for (int i = 0; i < n; i++) ranks[sa[i]] = i;
    ranks[n] = -1;

    s[sa[0]] = 'a';
    int i, j;
    for (i = 1, j = 'a'; i < n && j <= 'z'; i++) {
      if (ranks[sa[i - 1] + 1] > ranks[sa[i] + 1]) ++j;
      s[sa[i]] = j;
    }

    if (j <= 'z') {
      cout << s << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
