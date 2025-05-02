// Title : 특공대
// Link  : https://www.acmicpc.net/problem/4008 
// Time  : 84 ms
// Memory: 26724 KB

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

    while (ptr + 1 < lines.size() && F(ptr) <= F(ptr + 1)) ++ptr;
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

  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int64_t ga = -2ll * a;

  CHT cht;
  cht.Init();

  auto F = [&]() {

  };

  int64_t ans = 0, sum = 0, nxt;
  for (int i = 0; i < n; i++) {
    cin >> nxt;
    nxt += sum;
    int64_t g = ga * sum;
    int64_t y = sum * (a * sum - b) + ans;
    cht.AddLine(g, y);
    ans = max<int64_t>(cht.Query(nxt), 0) + nxt * (a *nxt + b) + c;
    sum = nxt;
  }
  cout << ans;

  return 0;
}