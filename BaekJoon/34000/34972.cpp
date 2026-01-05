// Title : A-머신
// Link  : https://www.acmicpc.net/problem/34972 
// Time  : 0 ms
// Memory: 18408 KB

#include <bits/stdc++.h>

using namespace std;

// [상태 4] [현위치 5] [테이프 15]
int8_t vis[1 << 24];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char s;
  int n, l;
  cin >> s >> n >> l;

  vector<array<int, 5>> cmd(n);
  for (int i = 0; i < n; i++) {
    char a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int x = 1;
    if (e == '-') x = -1, cin >> e;
    cmd[i] = {a - 'A', b - '0', c - '0', d - 'A', x};
  }

  auto GetState = [&](int st, int pos, int cur) {
    return (st << 20) | (pos << 15) | cur;
  };

  auto GetNext = [&](int state) {
    int cs = (state >> 20), cp = (state >> 15) & 0x1f, cv = (state & ((1 << 15) - 1));
    int cc = (cv >> cp) & 1;
    for (auto [a, b, c, d, e] : cmd) {
      if (a == cs && b == cc) {
        int cur = cv;
        if (cc != c) cur ^= (1 << cp);

        int pos = cp += e;
        if (!(0 <= pos && pos < l)) return -1;

        return GetState(d, pos, cur);
      }
    }
    return -1;
  };

  string sss;
  cin >> sss;
  reverse(sss.begin(), sss.end());
  int state = GetState(s - 'A', 0, stoi(sss, 0, 2));

  for (;;) {
    int cs = (state >> 20), cp = (state >> 15) & 0x1f, cv = (state & ((1 << 15) - 1));
    vis[state] = 1;
    int nxt = GetNext(state);
    if (nxt == -1) {
      cout << "STOP";
      return 0;
    } else if (vis[nxt]) {
      cout << "CONTINUE";
      return 0;
    }
    state = nxt;
  }

  return 0;
}