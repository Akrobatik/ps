// Title : 특공대
// Link  : https://www.acmicpc.net/problem/4008 
// Time  : 96 ms
// Memory: 38452 KB

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
  vector<int64_t> memo(n + 1);
  vector<int> fwd(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> fwd[i];
    fwd[i] += fwd[i - 1];
  }

  auto F = [&](int i) {
    int64_t x = fwd[i];
    return x * (x * a + b) + c;
  };

  auto G = [&](int i) {
    return -2ll * a * fwd[i];
  };

  auto Y = [&](int i) {
    int64_t x = fwd[i];
    return x * (a * x - b) + memo[i];
  };

  CHT cht;
  cht.Init();
  for (int i = 1; i <= n; i++) {
    cht.AddLine(G(i - 1), Y(i - 1));
    memo[i] = max<int64_t>(cht.Query(fwd[i]), 0) + F(i);
  }
  cout << memo[n];

  return 0;
}