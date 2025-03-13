#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    s += s;
    int n2 = n << 1;

    int ans, i = 0;
    while (i < n) {
      ans = i;
      int k = i, j = i + 1;
      while (j < n2 && s[j] >= s[k]) {
        if (s[j++] != s[k++]) k = i;
      }
      i += (j - i) / (j - k) * (j - k);
    }
    cout << ans << "\n";
  }

  return 0;
}
