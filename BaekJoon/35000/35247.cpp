// Title : Itsy Bits
// Link  : https://www.acmicpc.net/problem/35247 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64_t n;
  cin >> n;

  int bw = bit_ceil((uint32_t)bit_width(n));
  cout << bw << (bw > 1 ? " bits" : " bit");

  return 0;
}