// Title : even 하게 익은 SCON
// Link  : https://www.acmicpc.net/problem/33913 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;
constexpr int kInv2 = 500000004;

int64_t Power(int64_t x, int64_t exp) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = res * x % kMod;
    x = x * x % kMod;
    exp >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << (Power(26, n) + Power(22, n)) * kInv2 % kMod;

  return 0;
}