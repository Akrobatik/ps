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
