#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 10007;

int64_t Comb(int n, int r) {
  int64_t v = 1;
  if (n - r < r) r = n - r;
  for (int i = 0; i < r; i++) {
    v *= n - i;
    v /= (i + 1);
  }
  return v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t ans1 = 0, ans2 = 0;
  for (int i = 4; i <= n; i += 4) {
    int64_t v = Comb(13, i >> 2) * Comb(52 - i, n - i);
    if ((i >> 2) & 1) {
      ans1 += v;
    } else {
      ans2 += v;
    }
  }

  cout << abs(ans1 - ans2) % kMod;

  return 0;
}
