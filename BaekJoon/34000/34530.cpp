// Title : Back to Origin
// Link  : https://www.acmicpc.net/problem/34530 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int64_t LCM(int64_t a, int64_t b) {
  return a * b / GCD(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  cout << LCM(n, 360) / n;

  return 0;
}