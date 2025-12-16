// Title : 이진수 게임
// Link  : https://www.acmicpc.net/problem/18112 
// Time  : 40 ms
// Memory: 6784 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  int v1 = stoi(s1, 0, 2);
  int v2 = stoi(s2, 0, 2);

  vector<int> memo(1 << 20, -1);
  queue<int> q;

  auto Push = [&](int x, int v) {
    if (!(0 <= x && x < (1 << 20))) return;
    if (memo[x] != -1) return;
    memo[x] = v;
    q.push(x);
  };

  Push(v1, 0);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    int nv = memo[cur] + 1;
    int bw = bit_width((uint32_t)cur);
    for (int i = 1; i < bw; i++) {
      int nxt = cur ^ (1 << (i - 1));
      Push(nxt, nv);
    }
    Push(cur + 1, nv);
    Push(cur - 1, nv);
  }

  cout << memo[v2];

  return 0;
}