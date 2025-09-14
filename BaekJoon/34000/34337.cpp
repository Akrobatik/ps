// Title : 예티와 주사위 던지기
// Link  : https://www.acmicpc.net/problem/34337 
// Time  : 0 ms
// Memory: 2088 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[5];
  for (auto& e : arr) cin >> e;

  auto Calc = [&]() {
    int cnt[7] = {};
    for (auto e : arr) ++cnt[e];

    int maxx = 0;
    for (int i = 1; i <= 6; i++) {
      int x = cnt[i];
      if (x == 5) {
        maxx = 50;
      } else {
        maxx = max<int>(maxx, x * i);
      }
    }
    return maxx;
  };

  vector<int> axr;
  int limit = 1 << 5, ans = 0;
  for (int i = 0; i < limit; i++) {
    axr.clear();
    for (int j = 0; j < 5; j++) {
      if (i & (1 << j)) axr.push_back(j);
    }

    int mul = 1;
    for (int j = axr.size(); j < 5; j++) mul *= 6;

    int sum = 0;
    [&](this auto&& self, int idx) {
      if (idx == axr.size()) {
        sum += Calc();
        return;
      }

      int id = axr[idx], old = arr[id];
      for (int k = 1; k <= 6; k++) {
        arr[id] = k;
        self(idx + 1);
      }
      arr[id] = old;
    }(0);

    ans = max<int>(ans, sum * mul);
  }
  cout << ans;

  return 0;
}
