// Title : 뮤탈리스크
// Link  : https://www.acmicpc.net/problem/12869 
// Time  : 0 ms
// Memory: 2376 KB

#include <bits/stdc++.h>

using namespace std;

constexpr tuple<int, int, int> kDelta[] = {
    {1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1}};

bool visited[61][61][61];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int arr[3] = {};
  for (int i = 0; i < n; i++) cin >> arr[i];

  queue<tuple<int, int, int>> q;

  auto Push = [&](int a, int b, int c, int da, int db, int dc) {
    if ((a -= da) < 0) a = 0;
    if ((b -= db) < 0) b = 0;
    if ((c -= dc) < 0) c = 0;
    if (visited[a][b][c]) return;
    visited[a][b][c] = true;
    q.push({a, b, c});
  };

  Push(arr[0], arr[1], arr[2], 0, 0, 0);
  for (int i = 0;; i++) {
    int nq = q.size();
    while (nq--) {
      auto [a, b, c] = q.front();
      q.pop();

      if (a == 0 && b == 0 && c == 0) {
        cout << i;
        return 0;
      }

      for (auto [da, db, dc] : kDelta) {
        Push(a, b, c, da, db, dc);
      }
    }
  }

  return 0;
}
