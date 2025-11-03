// Title : Impact
// Link  : https://www.acmicpc.net/problem/34656 
// Time  : 4 ms
// Memory: 2292 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  deque<int> dq[2], spc[2];
  vector<int> cnt[2];
  for (int i = 0; i < 2; i++) {
    int m;
    cin >> m;
    cnt[i].assign(n + 1, 0);
    while (m--) {
      int x;
      cin >> x;
      dq[i].push_back(x);
      spc[i].push_back(0);
      ++cnt[i][x];
    }
  }

  vector<pair<int, int>> ans;

  auto Move = [&](int src, int dst) {
    assert(!dq[src].empty() && dq[dst].size() <= n + 1);

    int x = dq[src].front();
    dq[src].pop_front();
    dq[dst].push_back(x);
    --cnt[src][x], ++cnt[dst][x];
    ans.push_back({src + 1, dst + 1});
    assert(ans.size() <= 200000);

    int y = spc[src].front();
    spc[src].pop_front();
    spc[dst].push_back(y);
  };

  auto Check = [&]() {
    for (int t = 0; t < 2; t++) {
      for (int i = 1; i <= n; i++) {
        if (cnt[t][i] != 1) return false;
      }
    }
    return true;
  };

  while (!Check()) {
    int t = (dq[0].size() < dq[1].size() ? 1 : 0);
    if (dq[t].size() == n) {
      while (cnt[t][dq[t].front()] < 2) Move(t, t);
    }
    Move(t, t ^ 1);
  }

  for (int i = 1; i <= n; i++) {
    while (dq[0].front() != i) Move(0, 0);
    Move(0, 1);
    Move(1, 0);
  }

  for (int i = 1; i <= n; i++) {
    while (dq[0].front() != i || spc[0].front() != 0) Move(0, 0);
    Move(0, 1);
    for (;;) {
      bool ok = true;
      int st = spc[0].size() - i + 1;
      for (int j = 0; ok && j + 1 < i; j++) {
        ok = (spc[0][st + j] != 0);
      }
      if (ok) break;
      Move(0, 0);
    }
    Move(1, 0);
    spc[0].back() = 1;
  }

  cout << ans.size() << "\n";
  for (auto [a, b] : ans) cout << a << " " << b << "\n";

  for (int t = 0; t < 2; t++) {
    for (int i = 1; i <= n; i++) {
      assert(dq[t].front() == i);
      dq[t].pop_front();
    }
  }

  return 0;
}