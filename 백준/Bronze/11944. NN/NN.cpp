#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m;
  cin >> n >> m;
  string s = to_string(n);
  int64_t limit = min<int64_t>(n * s.size(), m);
  for (int64_t i = 0; i < limit; i++) {
    cout << s[i % s.size()];
  }

  return 0;
}
