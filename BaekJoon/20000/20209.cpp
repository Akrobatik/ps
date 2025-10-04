// Title : 스트레이트 스위치 게임
// Link  : https://www.acmicpc.net/problem/20209 
// Time  : 8 ms
// Memory: 2088 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> g(k);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    g[i].resize(x);
    for (auto& e : g[i]) cin >> e;
  }

  int minn = INT_MAX;
  [&](this auto&& self, int idx, int sum) -> void {
    if (idx == k) {
      int val = arr[1] % 5;
      bool ok = true;
      for (int i = 1; ok && i <= n; i++) {
        ok = (arr[i] % 5 == val);
      }
      if (ok) minn = min<int>(minn, sum);
      return;
    }

    for (int i = 0; i < 5; i++) {
      for (auto e : g[idx]) arr[e] += (idx + 1) * i;
      self(idx + 1, sum + i);
      for (auto e : g[idx]) arr[e] -= (idx + 1) * i;
    }
  }(0, 0);

  cout << (minn != INT_MAX ? minn : -1);

  return 0;
}