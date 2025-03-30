#include <bits/stdc++.h>

using namespace std;

int memo[200001];

bool Check(int n, int k, int x, int mid) {
  int lm = n - mid + 1;
  for (int i = 1; i <= lm; i++) {
    int fwd = memo[i - 1] * x;
    int bwd = memo[n] - memo[i + mid - 1];
    if (fwd + bwd >= k) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> memo[i];
  }
  partial_sum(memo, memo + n + 1, memo);

  int lo = 0, hi = n;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(n, k, x, mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << (lo ? lo : -1);

  return 0;
}