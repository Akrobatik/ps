// Title : 파티 홍보
// Link  : https://www.acmicpc.net/problem/34404 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int64_t, int64_t>> arr(n);
  for (int i = 0; i < n; i++) {
    int64_t x, y, p, q;
    cin >> x >> y >> p >> q;
    arr[i] = {x + p, y + q};
  }

  int cnt = 0;

  int64_t a, b;
  cin >> a >> b;
  for (auto [x, y] : arr) {
    int64_t z = a * x + b * 2;
    cnt += (z < y);
  }
  cout << cnt;

  return 0;
}