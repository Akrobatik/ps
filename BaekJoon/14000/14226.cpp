// Title : 이모티콘
// Link  : https://www.acmicpc.net/problem/14226 
// Time  : 4 ms
// Memory: 3336 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  unordered_set<int> memo;
  queue<pair<int, int>> q;
  memo.insert(0);

  auto Push = [&](int x, int y) {
    if (x <= 0 || x > n * 2) return;
    int xy = (x << 16) | y;
    if (!memo.insert(xy).second) return;
    q.push({x, y});
  };

  Push(1, 0);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [x, y] = q.front();
      q.pop();

      if (x == n) {
        cout << i;
        return 0;
      }

      Push(x, x);
      Push(x + y, y);
      Push(x - 1, y);
    }
  }

  return 0;
}
