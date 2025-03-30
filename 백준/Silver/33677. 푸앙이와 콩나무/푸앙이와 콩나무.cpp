#include <bits/stdc++.h>

using namespace std;

int order[1000001];
int memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill_n(order, 1000001, INT_MAX);
  fill_n(memo, 1000001, INT_MAX);

  pair<int64_t, int64_t> nxts[3];

  int n;
  cin >> n;
  queue<int> q;
  order[0] = -1;
  memo[0] = 0;
  q.push(0);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int64_t x = q.front();
      q.pop();

      int y = memo[x];
      if (x == n) {
        cout << i << " " << y;
        return 0;
      }

      nxts[0] = {x + 1, y + 1};
      nxts[1] = {x * 3, y + 3};
      nxts[2] = {x * x, y + 5};
      for (auto [xx, yy] : nxts) {
        if (xx > n || order[xx] < i) continue;
        memo[xx] = min<int>(memo[xx], yy);
        if (order[xx] != i) {
          order[xx] = i;
          q.push(xx);
        }
      }
    }
  }

  return 0;
}