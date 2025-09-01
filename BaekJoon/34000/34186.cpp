// Title : 17마리 낙타
// Link  : https://www.acmicpc.net/problem/34186 
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

  int t;
  cin >> t;
  while (t--) {
    int64_t n, a, b, c;
    cin >> n >> a >> b >> c;

    int64_t l = LCM(LCM(a, b), c);
    int64_t ra = l / a, rb = l / b, rc = l / c;
    int64_t rs = ra + rb + rc;
    if (rs > l || n % rs) {
      cout << "-1\n";
      continue;
    }

    cout << (n / rs) * l - n << "\n";
  }

  return 0;
}
