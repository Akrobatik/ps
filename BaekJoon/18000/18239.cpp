// Title : 편안한 수열 만들기
// Link  : https://www.acmicpc.net/problem/18239 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  if (n == 3) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  if (min<int>(k, n - k) >= 2) {
    pair<int, int> lr[5] = {{1, k}, {k + 1, n}, {1, n}, {1, n}, {1, n}};
    for (auto [l, r] : lr) {
      cout << "reverse " << l << " " << r << "\n";
    }
  } else if (n == 2) {
    pair<int, int> lr[5] = {{1, n}, {1, n}, {1, n}, {1, n}, {1, n}};
    for (auto [l, r] : lr) {
      cout << "swap " << l << " " << r << "\n";
    }
  } else {
    int x = (k == 1 ? 1 : 0);
    pair<int, int> lr[5] = {{1, 4}, {2, 3}, {1, 4}, {1 + x, n + x - 1}, {1, n}};
    for (int i = 0; i < 5; i++) {
      auto [l, r] = lr[i];
      cout << (i < 2 ? "swap " : "reverse ") << l << " " << r << "\n";
    }
  }

  return 0;
}