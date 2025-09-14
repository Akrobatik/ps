// Title : 여우 덧셈
// Link  : https://www.acmicpc.net/problem/34338 
// Time  : 100 ms
// Memory: 41152 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

int memo[1000][1000][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(memo, -1, sizeof(memo));

  string s1, s2;
  cin >> s1 >> s2;
  int n1 = s1.size(), n2 = s2.size();

  int ans = [&](this auto&& self, int st, int idx, int r) {
    if (st == n1) return (idx == n2 && r == 0) ? 0 : kInf;
    if (idx == n2) return kInf;

    auto& res = memo[st][idx][r];
    if (res != -1) return res;
    res = kInf;

    int x = s1[st] - '0';
    res = min<int>(res, self(st + 1, idx, r) + (x ? 1 : 0));
    if (r == s2[idx] - '0') res = min<int>(res, self(st + 1, idx + 1, 0) + (x ? 1 : 0));

    int nr = (r + x) % 10;
    res = min<int>(res, self(st + 1, idx, nr));
    if (nr == s2[idx] - '0') res = min<int>(res, self(st + 1, idx + 1, 0));

    return res;
  }(0, 0, 0);

  cout << (ans != kInf ? ans : -1);

  return 0;
}
