// Title : 2의 제곱인가？
// Link  : https://www.acmicpc.net/problem/11966
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  bitset<64> bits(n);
  cout << (bits.count() == 1 ? 1 : 0);

  return 0;
}
