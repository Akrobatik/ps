// Title : 부품 테스트
// Link  : https://www.acmicpc.net/problem/4698
// Time  : 40 ms
// Memory: 3084 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  map<int, int, greater<int>> items;
  map<int, int> mans;
  while (cin >> n >> m && n) {
    int64_t niall = 0, riall = 0;
    items.clear();
    while (n--) {
      int ni, ri;
      cin >> ni >> ri;
      if (ri) {
        items[ri] += ni;
        niall += ni;
        riall += (int64_t)ri * ni;
      }
    }

    int64_t nmall = 0, rmall = 0;
    mans.clear();
    while (m--) {
      int nm, rm;
      cin >> nm >> rm;
      if (rm) {
        mans[rm] += nm;
        nmall += nm;
        rmall += (int64_t)rm * nm;
      }
    }

    bool ok = riall <= rmall;
    int ci = 0, cm = 0, rem = min<int64_t>(niall, (--mans.end())->first);
    int64_t cur = 0;
    auto mit = mans.begin();
    auto iit = items.begin();
    while (ok && rem && iit != items.end()) {
      auto [ri, ni] = *iit++;
      ni = min<int>(ni, rem);
      rem -= ni;
      cur += (int64_t)ri * ni;
      ci += ni;
      while (mit != mans.end() && mit->first < ci) {
        auto [rm, nm] = *mit++;
        cm += nm;
        cur -= (int64_t)rm * nm;
      }
      ok = cur - ci * (nmall - cm) <= 0;
    }
    cout << ok << "\n";
  }

  return 0;
}
