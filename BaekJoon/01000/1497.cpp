// Title : 기타콘서트
// Link  : https://www.acmicpc.net/problem/1497 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int64_t> arr(n);
  for (auto& e : arr) {
    string s;
    cin >> s >> s;
    for (int i = 0; i < m; i++) {
      if (s[i] != 'Y') continue;
      e |= (1LL << i);
    }
  }

  int nb = 1 << n;
  int maxv = 0, minc = INT_MAX;
  for (int i = 1; i < nb; i++) {
    int x = i;
    int64_t mask = 0;
    while (x) {
      int lsb = x & -x;
      x ^= lsb;
      mask |= arr[__builtin_ctz(lsb)];
    }
    int val = __builtin_popcountll(mask);
    int cnt = __builtin_popcount(i);
    if (maxv < val || (maxv == val && minc > cnt)) maxv = val, minc = cnt;
  }
  cout << (maxv > 0 ? minc : -1);

  return 0;
}