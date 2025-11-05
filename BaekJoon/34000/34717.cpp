// Title : 코인과 쿼리
// Link  : https://www.acmicpc.net/problem/34717 
// Time  : 764 ms
// Memory: 228820 KB

#include <bits/stdc++.h>

using namespace std;

struct CHT {
  using Line = pair<int64_t, int64_t>;

  CHT() : lines{}, ptr(0) {}

  void AddLine(int64_t a, int64_t b) {
    Line line = {a, b};
    while (ptr + 1 < lines.size() && Check(lines[lines.size() - 2], lines.back(), line)) lines.pop_back();
    lines.push_back(line);
  }

  int64_t Query(int64_t x) {
    auto F = [&](int i) {
      auto [a, b] = lines[i];
      return a * x + b;
    };

    while (ptr + 1 < lines.size() && F(ptr) <= F(ptr + 1)) ++ptr;
    return F(ptr);
  }

  bool Check(const Line& a, const Line& b, const Line& c) {
    auto [aa, ab] = a;
    auto [ba, bb] = b;
    auto [ca, cb] = c;
    return (__int128_t)(bb - cb) * (ca - aa) <= (__int128_t)(ca - ba) * (ab - cb);
  }

  vector<Line> lines;
  int ptr;
};

using tup = tuple<int, int, int, int>;

constexpr int64_t kInf = 1e18;
constexpr int kMax = 1 << 19;
CHT tree[kMax << 1];

int64_t Query(int l, int r, int64_t x) {
  int64_t res = -kInf;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max<int64_t>(res, tree[l++].Query(x));
    if (r & 1) res = max<int64_t>(res, tree[--r].Query(x));
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int64_t> arr(n + 1), fwd(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    fwd[i] = fwd[i - 1] + arr[i];
  }

  for (int i = 0; i <= n; i++) {
    tree[i + kMax].AddLine(i, fwd[i]);
  }

  for (int i = kMax - 1; i > 0; i--) {
    auto& node = tree[i];
    for (auto [a, b] : tree[i << 1].lines) node.AddLine(a, b);
    for (auto [a, b] : tree[i << 1 | 1].lines) node.AddLine(a, b);
  }

  vector<tup> qr(m);
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    qr[i] = {l, r, x, i};
  }
  sort(qr.begin(), qr.end(), [&](const tup& lhs, const tup& rhs) {
    return arr[get<2>(lhs)] > arr[get<2>(rhs)];
  });

  vector<int64_t> ans(m);
  for (auto [l, r, x, i] : qr) {
    int64_t v = arr[x], s = fwd[x];
    ans[i] = max<int64_t>(v * x - s + Query(l - 1, r - 1, -v), 0);
  }
  for (auto e : ans) cout << e << "\n";

  return 0;
}