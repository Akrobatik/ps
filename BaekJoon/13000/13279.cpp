// Title : 곱의 합 쿼리
// Link  : https://www.acmicpc.net/problem/13279
// Time  : 1148 ms
// Memory: 2500 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e5 + 3;

int64_t memo[30001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  memo[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = n; j > 0; j--) {
      memo[j] = (memo[j] + memo[j - 1] * arr[i]) % kMod;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << memo[x] << "\n";
  }

  return 0;
}
