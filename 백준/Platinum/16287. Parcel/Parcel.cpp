#include <bits/stdc++.h>

using namespace std;

struct Subset {
  Subset(int _a, int _b) : s(_a + _b), a(_a), b(_b) {}
  Subset(int _s) : s(_s), a(0), b(0) {}

  constexpr auto operator<=>(const Subset& other) const {
    return s <=> other.s;
  }

  int s, a, b;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, n;
  cin >> w >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  vector<Subset> ab;
  ab.reserve((n * (n - 1)) / 2);
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) ab.emplace_back(a[i], a[j]);
  }
  sort(ab.begin(), ab.end());
  vector<Subset> cd(ab);

  auto ab_it = ab.begin(), ab_end = ab.end();
  auto cd_it = cd.rbegin(), cd_end = cd.rend();
  while (ab_it != ab_end && cd_it != cd_end) {
    int abv = ab_it->s;
    int cdv = cd_it->s;
    if (abv + cdv == w) {
      vector<pair<int, int>> ab_cands;
      while (ab_it != ab_end && ab_it->s == abv) ab_cands.push_back({ab_it->a, ab_it->b}), ++ab_it;
      vector<pair<int, int>> cd_cands;
      while (cd_it != cd_end && cd_it->s == cdv) cd_cands.push_back({cd_it->a, cd_it->b}), ++cd_it;
      for (auto [aa, bb] : ab_cands) {
        for (auto [cc, dd] : cd_cands) {
          if (aa != cc && aa != bb && aa != dd && bb != cc && bb != cc && bb != dd && cc != dd) {
            cout << "YES" << endl;
            return 0;
          }
        }
      }
    } else if (abv + cdv < w) {
      ab_it = lower_bound(ab_it + 1, ab_end, Subset(w - cdv));
    } else {
      cd_it = lower_bound(cd_it + 1, cd_end, Subset(w - abv), greater<>());
    }
  }
  cout << "NO" << endl;
  return 0;
}
