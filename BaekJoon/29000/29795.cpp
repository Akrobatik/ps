// Title : 한 대
// Link  : https://www.acmicpc.net/problem/29795 
// Time  : 196 ms
// Memory: 8884 KB

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

    int lo = ptr, hi = lines.size();
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (F(mid - 1) <= F(mid)) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    ptr = lo;

    return F(ptr);
  }

  // private:
  bool Check(const Line& a, const Line& b, const Line& c) {
    auto [aa, ab] = a;
    auto [ba, bb] = b;
    auto [ca, cb] = c;
    return (__int128_t)(bb - cb) * (ca - aa) <= (__int128_t)(ca - ba) * (ab - cb);
  }

  vector<Line> lines;
  int ptr;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<pair<int64_t, int64_t>> skills(n);
  for (auto& [a, b] : skills) cin >> a >> b;

  sort(skills.begin(), skills.end(), greater<pair<int64_t, int64_t>>());

  CHT cht;
  cht.Init();

  int idx = 0;
  vector<pair<int64_t, int64_t>> arr;
  while (idx < n) {
    auto [a, b] = skills[idx++];
    arr.push_back({a, b});
    while (idx < n && skills[idx].second <= b) ++idx;
  }

  if (arr.back().first == 1 && arr.back().second <= 0) arr.pop_back();

  if (arr.empty()) {
    while (q--) {
      int64_t x, y;
      cin >> x >> y;
      cout << (x >= y ? "0\n" : "-1\n");
    }
    return 0;
  }

  for (auto [a, b] : views::reverse(arr)) cht.AddLine(a, b);

  int64_t by = 0;
  auto& lines = cht.lines;
  if (lines[0].first == 1) {
    if (lines.size() == 1) {
      by = 1e12;
    } else {
      auto [a1, b1] = lines[0];
      auto [a2, b2] = lines[1];

      int64_t lo = 0, hi = 1e12 + 1;
      while (lo + 1 < hi) {
        int64_t mid = (lo + hi) >> 1;
        __int128_t v1 = (__int128_t)a1 * mid + b1;
        __int128_t v2 = (__int128_t)a2 * mid + b2;
        if (v1 > v2) {
          lo = mid;
        } else {
          hi = mid;
        }
      }
      by = lo;
    }
  }

  while (q--) {
    cht.ptr = 0;

    int64_t x, y;
    cin >> x >> y;

    int64_t cnt = 0;
    int64_t cy = min<int64_t>(by, y);
    if (x < cy) {
      auto [a, b] = lines[0];
      cnt = (cy - x) / b;
      x += cnt * b;
    }

    while (x < y) {
      int64_t nxt = cht.Query(x);
      if (nxt <= x) {
        cnt = -1;
        break;
      }
      ++cnt, x = nxt;
    }
    cout << cnt << "\n";
  }

  return 0;
}
