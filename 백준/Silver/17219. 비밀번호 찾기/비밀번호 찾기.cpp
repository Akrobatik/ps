#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  map<string, string> mp;
  while (n--) {
    string site, pw;
    cin >> site >> pw;
    mp[site] = pw;
  }
  while (m--) {
    string q;
    cin >> q;
    cout << mp[q] << "\n";
  }

  return 0;
}
