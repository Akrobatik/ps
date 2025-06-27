// Title : GCD 테이블
// Link  : https://www.acmicpc.net/problem/12972 
// Time  : 36 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<int, int, greater<int>> mp;
  for (int i = 0; i < n * n; i++) {
    int x;
    cin >> x;
    ++mp[x];
  }

  vector<int> ans;
  ans.reserve(n);

  for (int i = 0; i < n; i++) {
    auto it = mp.begin();
    int x = it->first;
    if (--(it->second) == 0) mp.erase(it);

    for (auto e : ans) {
      int g = GCD(x, e);
      auto jt = mp.find(g);
      if ((jt->second -= 2) == 0) mp.erase(jt);
    }

    ans.push_back(x);
  }

  for (auto e : ans) cout << e << " ";

  return 0;
}
