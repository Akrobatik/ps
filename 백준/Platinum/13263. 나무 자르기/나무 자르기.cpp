#include <bits/stdc++.h>

using namespace std;

// Convex Hull Trick
// https://m.blog.naver.com/jinhan814/222689836982
using i64 = long long;

struct PLL {
  i64 x, y;
  PLL(const i64 x = 0, const i64 y = 0) : x(x), y(y) {}
  bool operator<=(const PLL& i) const { return 1. * x / y <= 1. * i.x / i.y; }
};

struct ConvexHull {
 private:
  static i64 F(const PLL& i, const i64 x) { return i.x * x + i.y; }
  static PLL C(const PLL& a, const PLL& b) { return {a.y - b.y, b.x - a.x}; }
  deque<PLL> S;

 public:
  void Insert(const i64 a, const i64 b) {
    while (S.size() > 1 && C(S.back(), PLL(a, b)) <= C(S[S.size() - 2], S.back())) S.pop_back();
    S.push_back(PLL(a, b));
  }
  i64 Query(const i64 x) {
    while (S.size() > 1 && F(S[0], x) >= F(S[1], x)) S.pop_front();
    return F(S[0], x);
  }
} CHT;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;

  int64_t ans = 0;
  CHT.Insert(b[0], ans);
  for (int i = 1; i < n; i++) {
    ans = CHT.Query(a[i]);
    CHT.Insert(b[i], ans);
  }
  cout << ans;

  return 0;
}
