// Title : 연속 XOR
// Link  : https://www.acmicpc.net/problem/25306
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t XorSum(int64_t x) {
  if (x & 1) return ((x & 2) >> 1) ^ 1;
  return x + ((x & 2) >> 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;
  cout << (XorSum(a - 1) ^ XorSum(b));

  return 0;
}
