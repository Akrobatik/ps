// Title : 할인이 필요해
// Link  : https://www.acmicpc.net/problem/34323 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, s;
  cin >> n >> m >> s;

  int64_t mv = m * s;
  int64_t nv = (m + 1) * s * (100 - n) / 100;
  cout << min<int64_t>(mv, nv);

  return 0;
}
