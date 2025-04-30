// Title : 판치기
// Link  : https://www.acmicpc.net/problem/23085 
// Time  : 12 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;

  int cnt = 0;
  for (auto c : s) cnt += (c == 'H');

  queue<int> q;
  vector<bool> check(n + 1);

  auto Push = [&](int x) {
    if (!(0 <= x && x <= n) || check[x]) return;
    check[x] = true;
    q.push(x);
  };

  Push(cnt);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int x = q.front();
      q.pop();

      if (x == 0) {
        cout << i;
        return 0;
      }

      int y = n - x;
      for (int dx = 0; dx <= k; dx++) {
        int dy = k - dx;
        if (dx > x || dy > y) continue;
        Push(x - dx + dy);
      }
    }
  }
  cout << "-1";

  return 0;
}
