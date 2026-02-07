// Title : Pearls
// Link  : https://www.acmicpc.net/problem/35255 
// Time  : 72 ms
// Memory: 16836 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int na, nb, k, q;
  string s1, s2;
  cin >> na >> nb >> k >> q >> s1 >> s2;

  vector<vector<int8_t>> mat(256, vector<int8_t>(256));
  while (k--) {
    char u, v;
    cin >> u >> v;
    mat[u][v] = 1;
  }

  vector<string> unit(256);
  for (int i = 'a'; i <= 'z'; i++) {
    for (auto c : s2) {
      if (mat[i][c]) continue;
      unit[i].push_back(i);
      unit[i].push_back(c);
    }
  }

  int64_t len = 0;
  vector<int64_t> arr(na);
  for (int i = 0; i < na; i++) {
    arr[i] = len;
    len += unit[s1[i]].size();
  }

  while (q--) {
    int64_t x;
    cin >> x, x %= len;

    int idx = (upper_bound(arr.begin(), arr.end(), x) - arr.begin()) - 1;
    x -= arr[idx];
    cout << unit[s1[idx]][x] << "\n";
  }

  return 0;
}