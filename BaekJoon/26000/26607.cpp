// Title : 시로코와 은행털기
// Link  : https://www.acmicpc.net/problem/26607 
// Time  : 0 ms
// Memory: 2060 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, x;
  cin >> n >> k >> x;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e >> e;

  bitset<16001> memo[81];
  memo[0].set(0);
  for (int i = 0; i < n; i++) {
    for (int j = min<int>(i, k - 1); j >= 0; j--) {
      memo[j + 1] |= (memo[j] << arr[i]);
    }
  }

  int kx = k * x;
  int l = kx >> 1, r = kx - l;
  while (!memo[k].test(l) && !memo[k].test(r)) --l, ++r;
  cout << l * r;

  return 0;
}
