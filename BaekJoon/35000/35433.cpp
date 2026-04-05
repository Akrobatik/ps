// Title : 고속 프리렌 변환
// Link  : https://www.acmicpc.net/problem/35433 
// Time  : 276 ms
// Memory: 11928 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  int64_t mul = 1, div = 1, mlen = n + 1;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    int a, l;
    cin >> a >> l;
    mul *= a, div *= x - 1, mlen += l;
    arr[i] = l;
  }

  int m = 1 << n;
  vector<pair<int64_t, int64_t>> axr(m);
  for (int i = 0; i < m; i++) {
    int len = 0, sign = 1;
    for (int j = 0, k = i; j < n; j++, k >>= 1) {
      if (k & 1) {
        len += arr[j];
      } else {
        sign *= -1;
      }
    }

    axr[i] = {len, mul * sign};
  }
  sort(axr.begin(), axr.end(), greater<pair<int64_t, int64_t>>());

  string digits(mlen, '\0');
  int64_t carry = 0, flip = n & 1;
  for (int i = 0; i < mlen; i++) {
    int64_t val = carry;
    while (!axr.empty() && axr.back().first == i) val += axr.back().second, axr.pop_back();
    int64_t rem = val % x;
    if (rem < 0) rem += x;

    int64_t d = flip ? (rem ? x - rem : 0) : rem;
    digits[i] = d + '0';
    carry = (val - div * d) / x;
  }

  while (!digits.empty() && digits.back() == '0') digits.pop_back();
  reverse(digits.begin(), digits.end());

  cout << digits;

  return 0;
}