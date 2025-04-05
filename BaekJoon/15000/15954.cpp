// Title : 인형들
// Link  : https://www.acmicpc.net/problem/15954
// Time  : 24 ms
// Memory: 2040 KB

#include <bits/stdc++.h>

using namespace std;

int64_t arr[500], psum[501];

long double Std(int i, int k) {
  long double res = 0;
  long double m = (long double)(psum[i + k] - psum[i]) / k;
  for (int j = 0; j < k; j++) {
    long double x = m - arr[i + j];
    res += x * x;
  }
  return sqrtl(res / k);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  partial_sum(arr, arr + n, psum + 1);

  long double minn = LDBL_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = i + k - 1; j < n; j++) {
      long double s = Std(i, j - i + 1);
      if (minn > s) minn = s;
    }
  }
  cout.precision(6);
  cout << fixed << minn;

  return 0;
}
