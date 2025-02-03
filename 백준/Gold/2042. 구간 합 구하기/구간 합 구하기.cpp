#include <bits/stdc++.h>

using namespace std;

int64_t nums[1000001];
int64_t psum[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
    psum[i] = psum[i - 1] + nums[i];
  }

  map<int, int64_t> mp;
  int nn = m + k;
  for (int i = 0; i < nn; i++) {
    int a, b;
    int64_t c;
    cin >> a >> b >> c;
    if (a == 1) {
      mp[b] = c;
    } else {
      int64_t sum = psum[c] - psum[b - 1];
      for (auto [p, v] : mp) {
        if (p > c) break;
        if (p < b) continue;
        sum += v - nums[p];
      }
      cout << sum << "\n";
    }
  }

  return 0;
}
