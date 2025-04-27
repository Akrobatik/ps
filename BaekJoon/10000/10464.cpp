// Title : XOR
// Link  : https://www.acmicpc.net/problem/10464 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 30;

int Calc(int n) {
  int res = 0;
  if (!(n & 1)) res = n;
  if (bitset<2>(n % 4).count() == 1) ++res;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (Calc(b) ^ Calc(a - 1)) << "\n";
  }

  return 0;
}
