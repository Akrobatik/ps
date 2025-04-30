// Title : 시로코와 은행털기
// Link  : https://www.acmicpc.net/problem/26607 
// Time  : 64 ms
// Memory: 7388 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, x;
  cin >> n >> k >> x;
  int kx = k * x;
  int l = kx >> 1, r = kx - l;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e >> e;
  sort(arr.begin(), arr.end());

  int minn = 0, maxx = 0;
  for (int i = 0; i < k; i++) {
    minn += arr[i], maxx += arr[n - i - 1];
  }

  if (minn >= r) {
    cout << minn * (kx - minn);
    return 0;
  }
  if (maxx <= l) {
    cout << maxx * (kx - maxx);
    return 0;
  }

  bool memo[81][16001] = {};
  memo[0][0] = true;
  for (int i = 0; i < n; i++) {
    int v = arr[i];
    int lj = min<int>(i, k - 1);
    vector<pair<int, int>> nxt;
    for (int j = 0; j <= lj; j++) {
      int ls = lj * x;
      for (int s = 0; s <= ls; s++) {
        if (memo[j][s]) nxt.push_back({j + 1, s + v});
      }
    }
    for (auto [j, s] : nxt) memo[j][s] = true;
  }

  while (!memo[k][l] && !memo[k][r]) --l, ++r;
  cout << l * r;

  return 0;
}
