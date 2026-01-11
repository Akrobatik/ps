// Title : Ящик Пандоры
// Link  : https://www.acmicpc.net/problem/28800 
// Time  : 128 ms
// Memory: 21692 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;
constexpr int kInf = INT_MAX >> 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 3>> memo(n + 1, {kInf, 0, 0});
  vector<pair<int, int>> jmp(kMax + 1, {kInf, 0});
  memo[0] = {0, 0, 0};
  for (int i = 1, p = 0, x; i <= n; i++, p = x) {
    cin >> x;
    if (p <= x && memo[i - 1][0] < memo[i][0]) {
      memo[i] = {memo[i - 1][0], i - 1, 0};
    }
    if (jmp[x].first != kInf && jmp[x].first < memo[i][0]) {
      memo[i] = {jmp[x].first, jmp[x].second, 1};
    }
    if (jmp[x].first > memo[i][0] + 1) {
      jmp[x] = {memo[i][0] + 1, i};
    }
  }

  if (memo[n][0] == kInf) {
    cout << "-1";
    return 0;
  }

  int cur = n;
  vector<pair<int, int>> arr;
  while (cur) {
    auto [x, p, j] = memo[cur];
    if (j) arr.push_back({p, cur});
    cur = p;
  }

  cout << arr.size() << "\n";
  for (auto [l, r] : arr) cout << l << " " << r << "\n";

  return 0;
}