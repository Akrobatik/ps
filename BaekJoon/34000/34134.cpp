// Title : [Y] 새로운 요세푸스 문제
// Link  : https://www.acmicpc.net/problem/34134 
// Time  : 116 ms
// Memory: 4852 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 18;

int tree[kMax << 1];

void Dec(int idx) {
  int node = idx + kMax;
  while (node) --tree[node], node >>= 1;
}

int Query(int l, int r) {
  int res = 0;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree[l++];
    if (r & 1) res += tree[--r];
  }
  return res;
}

int Count(int l, int r, int n) {
  if (l == r) return 0;
  if (l < r) return Query(l + 1, r);
  return Query(l + 1, n) + Query(1, r);
}

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int64_t ExtGCD(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  x = 1, y = 0;
  int64_t x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int64_t q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

pair<int64_t, int64_t> CRT(const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) {
  auto [ar, am] = a;
  auto [br, bm] = b;
  int64_t x, y;
  int64_t g = ExtGCD(am, bm, x, y);
  int64_t l = am * bm / g;
  int64_t t = ((br - ar) / g) * x % (bm / g);
  if (t < 0) t += bm / g;
  return {(ar + am * t) % l, l};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    tree[i + kMax] = 1;
  }
  for (int i = kMax - 1; i > 0; i--) {
    tree[i] = tree[i << 1] + tree[(i << 1) + 1];
  }

  vector<int> arr(n);
  int old = n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = Count(old, x, n) % (n - i);
    Dec(x);
    old = x;
  }

  int idx = 0, ans = -1;
  while (idx < n) {
    ++ans;
    int64_t lv = arr[idx], ls = n - idx;
    while (++idx < n) {
      int64_t rv = arr[idx], rs = n - idx;
      int64_t g = GCD(ls, rs);
      if (abs(lv - rv) % g) break;

      auto [x, y] = CRT({lv, ls}, {rv, rs});
      if ((x %= y) <= 0) x += y;

      if (x > m) break;
      lv = x, ls = y;
    }
  }
  cout << ans;

  return 0;
}
