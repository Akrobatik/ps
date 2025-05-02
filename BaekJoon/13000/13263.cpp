// Title : 나무 자르기
// Link  : https://www.acmicpc.net/problem/13263 
// Time  : 28 ms
// Memory: 2804 KB

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
      return a * x + b;
    };

    while (ptr + 1 < lines.size() && F(ptr) >= F(ptr + 1)) ++ptr;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  CHT cht;
  cht.Init();

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;

  int64_t ans = 0;
  cht.AddLine(b[0], ans);
  for (int i = 1; i < n; i++) {
    ans = cht.Query(a[i]);
    cht.AddLine(b[i], ans);
  }
  cout << ans;

  return 0;
}