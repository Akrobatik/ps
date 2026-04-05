// Title : 고속 프리렌 변환
// Link  : https://www.acmicpc.net/problem/35433 
// Time  : 652 ms
// Memory: 80148 KB

#include <bits/stdc++.h>

using namespace std;

#define int int64_t
void Solve() {
  int n, x;
  cin >> n >> x;

  int mul = 1, div = 1, mlen = n + 1;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    int a, l;
    cin >> a >> l;
    mul *= a, div *= x - 1, mlen += l;
    arr[i] = l;
  }

  vector<int> digits(mlen);

  int m = 1 << n;
  for (int i = 0; i < m; i++) {
    int len = 0, sign = 1;
    for (int j = 0, k = i; j < n; j++, k >>= 1) {
      if (k & 1) {
        len += arr[j];
      } else {
        sign *= -1;
      }
    }

    digits[len] += mul * sign;
  }

  int carry = 0, flip = n & 1;
  for (int i = 0; i < mlen; i++) {
    int val = digits[i] + carry;
    int rem = val % x;
    if (rem < 0) rem += x;

    digits[i] = (flip ? (rem ? x - rem : 0) : rem);
    carry = (val - digits[i] * div) / x;
  }

  while (!digits.empty() && digits.back() == 0) digits.pop_back();

  for (auto e : views::reverse(digits)) cout << e;
}
#undef int

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();

  return 0;
}