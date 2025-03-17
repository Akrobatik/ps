#include <bits/stdc++.h>

using namespace std;

constexpr uint64_t kMod = 1e9;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (auto& e : a) cin >> e;
  int m;
  cin >> m;
  vector<int64_t> b(m);
  for (auto& e : b) cin >> e;

  bool of = false;
  int64_t gcd = 1;
  for (auto aa : a) {
    for (auto& bb : b) {
      int64_t x = GCD(aa, bb);
      gcd *= x;
      if (gcd >= kMod) of = true, gcd %= kMod;
      aa /= x, bb /= x;
    }
  }

  n = 0;
  char s[16];
  while ((of || gcd) && n < 9) s[n++] = gcd % 10 + '0', gcd /= 10;
  while (n--) cout << s[n];
  return 0;
}
