#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b, x;
  cin >> n >> m >> a >> b;
  vector<int> sch(n), memo(m + 1);
  for (auto& e : sch) cin >> e;
  while (a--) cin >> x, memo[x] = 1;
  while (b--) cin >> x, memo[x] = -1;

  int ans = 0;
  auto it = sch.begin();
  while (it != sch.end()) {
    int cur = memo[*it++], cnt = 1;
    while (it != sch.end() && memo[*it] == cur) ++it, ++cnt;
    if (cur && cnt >= 3) ans += cur * cnt;
  }
  cout << ans;

  return 0;
}
