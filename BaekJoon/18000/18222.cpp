// Title : 투에－모스 문자열
// Link  : https://www.acmicpc.net/problem/18222
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64_t k;
  cin >> k;
  cout << (bitset<64>(k - 1).count() & 1ull);

  return 0;
}
