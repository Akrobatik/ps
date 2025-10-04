// Title : 달력
// Link  : https://www.acmicpc.net/problem/20207 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int cnt[367] = {};
  for (int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    ++cnt[s], --cnt[e + 1];
  }

  for (int i = 1; i <= 365; i++) {
    cnt[i] += cnt[i - 1];
  }

  int64_t ans = 0;

  int idx = 1;
  while (idx <= 365) {
    if (cnt[idx] == 0) {
      ++idx;
      continue;
    }

    int nxt = idx, maxx = 0;
    while (nxt <= 365 && cnt[nxt] != 0) {
      maxx = max<int>(maxx, cnt[nxt++]);
    }
    ans += (int64_t)(nxt - idx) * maxx;
    idx = nxt;
  }
  cout << ans;

  return 0;
}