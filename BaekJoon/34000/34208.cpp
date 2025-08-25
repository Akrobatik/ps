// Title : 수열과 쿼리 46
// Link  : https://www.acmicpc.net/problem/34208 
// Time  : 700 ms
// Memory: 74448 KB

#include <bits/stdc++.h>

using namespace std;

struct CHT {
 private:
  using Line = pair<int64_t, int64_t>;

 public:
  void Init() {
    lines.clear();
    ptr = 0;
  }

  void AddLine(int64_t a, int64_t b) {
    Line line = {a, b};
    while (ptr + 1 < lines.size() && Check(lines[lines.size() - 2], lines.back(), line)) lines.pop_back();
    lines.push_back(line);
  }

  int64_t Query(int64_t x) {
    auto F = [&](int i) {
      auto [a, b] = lines[i];
      return (__int128_t)a * x + b;
    };

    int nl = lines.size();
    while (ptr + 1 < nl && F(ptr) <= F(ptr + 1)) ++ptr; 
    return F(ptr);
  }

 private:
  bool Check(const Line& a, const Line& b, const Line& c) {
    auto [aa, ab] = a;
    auto [ba, bb] = b;
    auto [ca, cb] = c;
    return (__int128_t)(bb - cb) * (ca - aa) <= (__int128_t)(ca - ba) * (ab - cb);
  }

  vector<Line> lines;
  int ptr;
};

constexpr int64_t kInf = INT64_MAX >> 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int64_t> arr(n + 1), axr(n + 1, -kInf);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + x;
  }

  vector<pair<int, int>> queries(q);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    queries[i] = {x, i};
  }
  sort(queries.begin(), queries.end());

  auto Sub = [&](const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) -> pair<int64_t, int64_t> {
    auto [ax, ay] = a;
    auto [bx, by] = b;
    return {ax - bx, ay - by};
  };

  auto Check = [&](const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b, const pair<int64_t, int64_t>& c) {
    auto [x1, y1] = Sub(b, a);
    auto [x2, y2] = Sub(c, a);

    // y1 / x1 <= y2 / x2
    return (__int128_t)y1 * x2 <= (__int128_t)y2 * x1;
  };

  vector<pair<int64_t, int64_t>> lrr, rrr, lxr, rxr, lr;
  [&](this auto&& self, int l, int r) {
    if (l == r) return;

    int mid = (l + r) >> 1;
    self(l, mid);
    self(mid + 1, r);

    lrr.clear(), rrr.clear();
    for (int i = mid; i >= l; i--) {
      pair<int64_t, int64_t> cur = {i, arr[i]};
      while (lrr.size() >= 2 && Check(lrr[lrr.size() - 2], lrr.back(), cur)) lrr.pop_back();
      lrr.push_back(cur);
    }

    for (int i = mid + 1; i <= r; i++) {
      pair<int64_t, int64_t> cur = {i, arr[i]};
      while (rrr.size() >= 2 && Check(rrr[rrr.size() - 2], rrr.back(), cur)) rrr.pop_back();
      rrr.push_back(cur);
    }

    lxr.clear(), rxr.clear();
    for (int i = 1; i < lrr.size(); i++) {
      lxr.push_back(Sub(lrr[i - 1], lrr[i]));
    }
    for (int i = 1; i < rrr.size(); i++) {
      rxr.push_back(Sub(rrr[i], rrr[i - 1]));
    }

    lr.resize(lxr.size() + rxr.size());
    merge(lxr.begin(), lxr.end(), rxr.begin(), rxr.end(), lr.begin(), [&](const pair<int64_t, int64_t>& lhs, const pair<int64_t, int64_t>& rhs) {
      return Check({0, 0}, rhs, lhs);
    });

    auto [cx, cy] = Sub(rrr[0], lrr[0]);
    axr[cx] = max<int64_t>(axr[cx], cy);
    for (auto [x, y] : lr) {
      cx += x, cy += y;
      axr[cx] = max<int64_t>(axr[cx], cy);
    }
  }(0, n);

  CHT cht;
  cht.Init();
  for (int i = 1; i <= n; i++) {
    if (axr[i] == -kInf) continue;
    cht.AddLine(i, axr[i]);
  }

  vector<int64_t> ans(q);
  for (auto [x, i] : queries) {
    ans[i] = cht.Query(x);
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}
