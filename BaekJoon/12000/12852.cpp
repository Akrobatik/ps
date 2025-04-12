// Title : 1로 만들기 2
// Link  : https://www.acmicpc.net/problem/12852 
// Time  : 0 ms
// Memory: 6908 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1000001];
bool visited[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  queue<int> q;
  auto Push = [&](int nxt, int cur) {
    memo[nxt] = cur;
    visited[nxt] = true;
    q.push(nxt);
  };

  int i;
  Push(n, n);
  for (i = 0; !memo[1]; i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      if (cur % 3 == 0 && !memo[cur / 3]) Push(cur / 3, cur);
      if (cur % 2 == 0 && !memo[cur / 2]) Push(cur / 2, cur);
      if (!memo[cur - 1]) Push(cur - 1, cur);
    }
  }

  vector<int> path;
  int p = 1;
  for (;;) {
    path.push_back(p);
    if (p == memo[p]) break;
    p = memo[p];
  }

  cout << i << "\n";
  for (auto p : views::reverse(path)) cout << p << " ";

  return 0;
}
