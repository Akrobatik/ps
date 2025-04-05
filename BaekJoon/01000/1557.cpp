// Title : 제곱 ㄴㄴ
// Link  : https://www.acmicpc.net/problem/1557
// Time  : 8 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 40558;
int mu[kMax + 1];

int64_t Count(int64_t n) {
  int64_t cnt = n;
  for (int64_t i = 2; i * i <= n; i++) {
    cnt += mu[i] * (n / (i * i));
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(mu, -1, sizeof(mu));
  mu[1] = 1;
  for (int i = 2; i <= kMax; i++) {
    for (int j = (i << 1); j <= kMax; j += i) {
      mu[j] -= mu[i];
    }
  }

  int64_t k;
  cin >> k;

  int64_t lo = k - 1, hi = 1644934082;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (Count(mid) < k) {
      lo = mid;
    } else {
      hi = mid;
    }
  };
  cout << lo + 1;

  return 0;
}
