#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e9 + 9;
constexpr int64_t kBase = 1299709;
constexpr int kMax = 360000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int tmp = a[0] - a[n - 1] + kMax;
  for (int i = 1; i < n; i++) {
    a[i - 1] = a[i] - a[i - 1];
  }
  a[n - 1] = tmp;
  tmp = b[0] - b[n - 1] + kMax;
  for (int i = 1; i < n; i++) {
    b[i - 1] = b[i] - b[i - 1];
  }
  b[n - 1] = tmp;

  vector<int64_t> p((n << 1) + 1);
  p[0] = 1;
  for (int i = 0; i < (n << 1); i++) {
    p[i + 1] = p[i] * kBase % kMod;
  }

  int64_t key = 0;
  for (int i = 0; i < n; i++) {
    key = (key + p[i] * (b[i] + 1)) % kMod;
  }
  key = key * p[n << 1] % kMod;

  vector<int64_t> h((n << 1) + 1);
  for (int i = 0; i < n; i++) {
    h[i + 1] = (h[i] + p[i] * (a[i] + 1)) % kMod;
  }

  for (int i = 0; i < n; i++) {
    if ((h[i + n] - h[i] + kMod) * p[(n << 1) - i] % kMod == key) {
      cout << "possible";
      return 0;
    }

    h[i + n + 1] = (h[i + n] + p[i + n] * (a[i] + 1)) % kMod;
  }
  cout << "impossible";

  return 0;
}
