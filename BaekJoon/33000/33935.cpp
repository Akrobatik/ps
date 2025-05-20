// Title : 체크박스 누르기 2
// Link  : https://www.acmicpc.net/problem/33935 
// Time  : 296 ms
// Memory: 3000 KB

#include <bits/stdc++.h>

using namespace std;

int64_t FloorSum(int64_t n, int64_t m, int64_t a, int64_t b) {
  int64_t res = 0;
  for (;;) {
    if (a >= m) {
      res += (n - 1) * n * (a / m) / 2;
      a %= m;
    }
    if (b >= m) {
      res += n * (b / m);
      b %= m;
    }

    int64_t ymax = a * n + b;
    if (ymax < m) break;

    n = ymax / m;
    b = ymax % m;
    swap(m, a);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  bitset<1000001> bits;
  for (int i = 0; i <= n; i++) {
    bits.set(i, FloorSum(n, n, i, i + n - 1) & 1);
  }

  string s(n, '.');
  for (int i = 0; i < n; i++) {
    if (bits.test(i) != bits.test(i + 1)) s[i] = 'V';
  }
  cout << s;

  return 0;
}
