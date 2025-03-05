#include <bits/stdc++.h>

using namespace std;

bool Check(string_view sv) {
  int n = sv.size(), half = n >> 1;
  bool ok = true;
  for (int i = 0; ok && i < half; i++) {
    ok = (sv[i] != sv[n - i - 1]);
  }
  return ok && (n == 1 || (Check(sv.substr(0, half)) && Check(sv.substr(half + 1))));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    cout << (Check(s) ? "YES\n" : "NO\n");
  }

  return 0;
}
