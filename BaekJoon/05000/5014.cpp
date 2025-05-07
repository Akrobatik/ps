// Title : 스타트링크
// Link  : https://www.acmicpc.net/problem/5014 
// Time  : 12 ms
// Memory: 2876 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;

  queue<int> q;
  bool visited[1000001] = {};

  auto Push = [&](int x) {
    if (x > f || x < 1 || visited[x]) return;
    visited[x] = true;
    q.push(x);
  };

  Push(s);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      if (cur == g) {
        cout << i;
        return 0;
      }

      for (auto nxt : {cur + u, cur - d}) {
        Push(nxt);
      }
    }
  }
  cout << "use the stairs";

  return 0;
}
