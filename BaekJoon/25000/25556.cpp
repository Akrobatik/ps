// Title : 포스택
// Link  : https://www.acmicpc.net/problem/25556 
// Time  : 216 ms
// Memory: 8760 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<int64_t, int64_t> memo[4];
  int64_t sum = 0, all = 0;

  int n;
  cin >> n;
  while (n--) {
    int64_t x;
    cin >> x;

    all += x;

    queue<pair<int64_t, int64_t>> q;
    q.push({x, x});
    for (int i = 0; !q.empty() && i < 4; i++) {
      int nq = q.size();
      while (nq--) {
        auto [v, r] = q.front();
        q.pop();

        int64_t rem = r;
        auto it = memo[i].upper_bound(v);
        while (rem && it != memo[i].end()) {
          int64_t cut = min<int64_t>(rem, it->second);
          sum -= cut, rem -= cut;
          q.push({it->first, cut});
          if ((it->second -= cut) == 0) it = memo[i].erase(it);
        }

        memo[i][v] += r;
        sum += r;
      }
    }
  }

  cout << (sum == all ? "YES" : "NO");

  return 0;
}