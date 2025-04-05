// Title : 2진수 뒤집기
// Link  : https://www.acmicpc.net/problem/11179
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64_t n;
  cin >> n;
  int sz = bit_width(n);
  bitset<64> b1(n), b2;
  for (int i = 0; i < sz; i++) {
    if (b1.test(i)) b2.set(sz - i - 1);
  }
  cout << b2.to_ullong();

  return 0;
}
