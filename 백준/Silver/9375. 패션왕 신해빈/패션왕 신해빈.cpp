#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<string, int> mp;
    while (n--) {
      string _, s;
      cin >> _ >> s;
      ++mp[s];
    }

    int ans = 1;
    for (auto& [_, cnt] : mp) ans *= (cnt + 1);
    cout << ans - 1 << "\n";
  }

  return 0;
}
