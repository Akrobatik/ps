// Title : 서버 로그
// Link  : https://www.acmicpc.net/problem/33920 
// Time  : 356 ms
// Memory: 16940 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  map<int, int, greater<int>> mp;
  while (n--) {
    int x;
    cin >> x;
    ++mp[x];
  }

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x, x -= i;

    int64_t cnt = 0, sum = 0;
    auto it = mp.begin();
    while (it != mp.end() && it->first > x) {
      auto [key, val] = *it;
      it = mp.erase(it);
      cnt += val, sum += (int64_t)(key - x) * val;
    }
    mp[x] += cnt;
    cout << sum << "\n";
  }

  return 0;
}