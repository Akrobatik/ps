// Title : 잃어버린 섬
// Link  : https://www.acmicpc.net/problem/34146 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e4;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cnt[kMax + 1] = {};

  int n, m;
  cin >> n >> m;
  int nm = n * m;
  while (nm--) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  int odd = 0;
  for (int i = 1; i <= kMax; i++) {
    odd += (cnt[i] & 1);
  }

  int req = (m & 1) ? n : 0;
  cout << (odd <= req && (odd & 1) == (req & 1) ? "YES" : "NO");

  return 0;
}
