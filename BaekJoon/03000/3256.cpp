// Title : 비행기
// Link  : https://www.acmicpc.net/problem/3256 
// Time  : 4 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  list<tup> ls;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ls.push_back({x, 0, 5});
  }

  for (int t = 0;; t++) {
    auto it = ls.begin();
    while (it != ls.end()) {
      auto& [g, p, r] = *it;
      if (g != p) {
        if (it == ls.begin() || get<1>(*prev(it)) > p + 1) {
          ++p;
        }
        ++it;
      } else {
        if (--r == 0) {
          it = ls.erase(it);
        } else {
          ++it;
        }
      }
    }

    if (ls.empty()) {
      cout << t;
      break;
    }
  }

  return 0;
}