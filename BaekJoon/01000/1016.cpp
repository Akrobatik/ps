// Title : 제곱 ㄴㄴ 수
// Link  : https://www.acmicpc.net/problem/1016 
// Time  : 44 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1000000;
int mu[kMax + 1];

int64_t Count(int64_t n) {
  int64_t cnt = n - (n >> 2);
  for (int64_t i = 3; i * i <= n; i++) {
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

  int64_t a, b;
  cin >> a >> b;
  cout << Count(b) - Count(a - 1);

  return 0;
}
