// Title : 접미사 배열 2
// Link  : https://www.acmicpc.net/problem/13013
// Time  : 0 ms
// Memory: 2084 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> sa(n);
  for (auto& e : sa) cin >> e;
  vector<int> str(n);
  for (int i = 0; i < n; i++) str[sa[i]] = i;

  auto Check = [&](int i, int j) {
    int limit = n - max<int>(i, j);
    for (int k = 0; k < limit; k++) {
      if (str[i + k] == str[j + k]) continue;
      return str[i + k] < str[j + k];
    }
    return i > j;
  };

  int ans = 1;
  for (int i = 1, j = 0; i < n; i++) {
    str[sa[i]] = j;
    if (!Check(sa[i - 1], sa[i])) {
      str[sa[i]] = ++j;
      ++ans;
    }
  }
  cout << ans;

  return 0;
}
