// Title : Stopki
// Link  : https://www.acmicpc.net/problem/8661 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t x, k, a;
  cin >> x >> k >> a;

  int64_t ka = k + a;
  x %= ka;
  cout << (x < k);

  return 0;
}