// Title : 쌓기나무
// Link  : https://www.acmicpc.net/problem/33713 
// Time  : 568 ms
// Memory: 51440 KB

#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>> fronts[200001], sides[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<int64_t, int> memo;
  int64_t fsum = 0, ssum = 0;

  int n, m, q;
  cin >> n >> m >> q;
  while (q--) {
    string cmd;
    cin >> cmd;
    switch (cmd[1]) {
      case 'T': {  // STACK
        int64_t x, y;
        cin >> x >> y;
        int h = ++memo[(x << 32) | y], omax, nmax;

        omax = fronts[x].empty() ? 0 : fronts[x].top().first;
        fronts[x].push({h, y});
        nmax = fronts[x].top().first;
        fsum += nmax - omax;

        omax = sides[y].empty() ? 0 : sides[y].top().first;
        sides[y].push({h, x});
        nmax = sides[y].top().first;
        ssum += nmax - omax;
      } break;
      case 'E': {  // REMOVE
        int64_t x, y;
        cin >> x >> y;
        if (auto it = memo.find((x << 32) | y); it != memo.end()) {
          int h = --it->second, omax, nmax;
          if (h == 0) memo.erase(it);

          omax = fronts[x].top().first;
          while (!fronts[x].empty()) {
            auto [hh, yy] = fronts[x].top();
            if (auto it2 = memo.find(((int64_t)x << 32) | yy); it2 != memo.end()) {
              if (it2->second == hh) break;
            }
            fronts[x].pop();
          }
          nmax = fronts[x].empty() ? 0 : fronts[x].top().first;
          fsum += nmax - omax;

          omax = sides[y].top().first;
          while (!sides[y].empty()) {
            auto [hh, xx] = sides[y].top();
            if (auto it2 = memo.find(((int64_t)xx << 32) | y); it2 != memo.end()) {
              if (it2->second == hh) break;
            }
            sides[y].pop();
          }
          nmax = sides[y].empty() ? 0 : sides[y].top().first;
          ssum += nmax - omax;
        }
      } break;
      case 'R': {  // FRONT
        cout << fsum << "\n";
      } break;
      case 'I': {  // SIDE
        cout << ssum << "\n";
      } break;
      case 'O': {  // TOP
        cout << memo.size() << "\n";
      } break;
    }
  }

  return 0;
}
