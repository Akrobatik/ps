#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  map<int, int> mp;
  while (n--) {
    int v;
    cin >> v;
    if (auto it = mp.find(v); it != mp.end()) {
      ++it->second;
    } else {
      mp.insert({v, 1});
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int v;
    cin >> v;
    if (auto it = mp.find(v); it != mp.end()) {
      cout << it->second << " ";
    } else {
      cout << "0 ";
    }
  }

  return 0;
}
