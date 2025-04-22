// Title : Professor KCM
// Link  : https://www.acmicpc.net/problem/13206 
// Time  : 228 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

vector<pair<int, int>> memo[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i <= 1000; i++) {
    int x = i;
    for (int j = 2; x != 1 && j * j <= i; j++) {
      if (x % j == 0) {
        int cnt = 0;
        while (x % j == 0) x /= j, ++cnt;
        memo[i].push_back({j, cnt});
      }
    }
    if (x != 1) memo[i].push_back({x, 1});
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> facts;
    while (n--) {
      int x;
      cin >> x;
      for (auto [p, cnt] : memo[x]) {
        facts[p] = max<int>(facts[p], cnt);
      }
    }

    int ans = 1;
    for (auto [p, cnt] : facts) {
      while (cnt--) ans = (int64_t)ans * p % kMod;
    }
    cout << ans << "\n";
  }

  return 0;
}
