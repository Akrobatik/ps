// Title : 뮤탈리스크 2
// Link  : https://www.acmicpc.net/problem/12870 
// Time  : 160 ms
// Memory: 6796 KB

#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> cands[20];
int memo[21][141][401];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j <= 7; j++) {
      for (int k = 0; k <= 20; k++) {
        int l = x - j * 9 - k * 3;
        if (l <= 0) {
          cands[i].push_back({j, k, 0});
          break;
        } else {
          cands[i].push_back({j, k, l});
        }
      }
      if (j * 9 >= x) break;
    }
    sort(cands[i].begin(), cands[i].end(), [&](const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
      auto [la, lb, lc] = lhs;
      auto [ra, rb, rc] = rhs;
      return la + lb + lc < ra + rb + rc;
    });
  }

  auto Check = [&](int limit) {
    memset(memo, 0x7f, sizeof(memo));
    memo[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (auto [a, b, c] : cands[i]) {
        if (a + b + c > limit) break;
        for (int j = 0; j <= i * 7; j++) {
          for (int k = 0; k <= i * 20; k++) {
            memo[i + 1][j + a][k + b] = min<int>(memo[i + 1][j + a][k + b], memo[i][j][k] + c);
          }
        }
      }
    }

    int minn = INT_MAX, maxx = 0;
    for (int i = 0; i <= n * 7; i++) {
      for (int j = 0; j <= n * 20; j++) {
        int k = memo[n][i][j];
        minn = min<int>(minn, max<int>({i, j, k}));
      }
    }
    return minn <= limit;
  };

  int lo = 0, hi = 140;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << hi;

  return 0;
}
