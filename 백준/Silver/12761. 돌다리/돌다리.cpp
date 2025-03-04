#include <bits/stdc++.h>

using namespace std;

bool memo[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, n, m;
  cin >> a >> b >> n >> m;
  queue<int> q;
  memo[n] = true;
  q.push(n);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto cur = q.front();
      q.pop();

      if (cur == m) {
        cout << i;
        return 0;
      }

      for (auto nxt : {cur - 1, cur + 1, cur + a, cur - a, cur + b, cur - b, cur * a, cur * b}) {
        if (0 <= nxt && nxt <= 100000 && !memo[nxt]) {
          memo[nxt] = true;
          q.push(nxt);
        }
      }
    }
  }

  return 0;
}
