// Title : Split the GSHS 5
// Link  : https://www.acmicpc.net/problem/35425 
// Time  : 80 ms
// Memory: 6712 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, c;
  cin >> n >> m >> c;

  vector<int> trr(n + 1), frr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> trr[i] >> frr[i], --frr[i];
  }

  vector<int64_t> memo(n + 1, kInf);
  memo[0] = 0;

  deque<int> dq;
  for (int i = 1; i <= n; i++) {
    while (!dq.empty() && dq.front() < i - c) dq.pop_front();
    while (!dq.empty() && frr[dq.back()] <= frr[i]) dq.pop_back();
    dq.push_back(i);

    int64_t mul = (i == n ? 1 : 2);
    for (auto it = dq.begin(); it != dq.end(); ++it) {
      int cur = *it;
      int prv = (it != dq.begin() ? *prev(it) : max<int>(i - c, 0));
      int64_t st = max<int64_t>(memo[prv], trr[i]);
      int64_t dist = frr[cur];
      memo[i] = min<int64_t>(memo[i], st + dist * mul);
    }
  }
  cout << memo[n];

  return 0;
}