// Title : 바구니 뒤집기
// Link  : https://www.acmicpc.net/problem/10811
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  iota(arr.begin(), arr.end(), 1);
  while (m--) {
    int l, r;
    cin >> l >> r;
    reverse(arr.begin() + l - 1, arr.begin() + r);
  }
  for (auto e : arr) cout << e << " ";

  return 0;
}
