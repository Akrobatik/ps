// Title : 힝스티비
// Link  : https://www.acmicpc.net/problem/34242 
// Time  : 8 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  auto Calc = [&](int a, int b, int c) {
    if (min<int>({a, b, c}) < 0 || max<int>({a, b, c}) >= n) return 0;
    if (s[a] == '+' && s[b] == '^' && s[c] == '+') return 1;
    if (s[a] == '-' && s[b] == '^' && s[c] == '-') return -1;
    return 0;
  };

  int cnt = 0;
  for (int i = 2; i < n; i++) {
    cnt += Calc(i - 2, i - 1, i);
  }

  int maxx = 0;
  for (int i = 0; i < n; i++) {
    int old = 0;
    for (int j = -1; j <= 1; j++) {
      old += Calc(i + j - 1, i + j, i + j + 1);
    }

    int cur = Calc(i - 2, i - 1, i + 1) + Calc(i - 1, i + 1, i + 2);
    maxx = max<int>(maxx, cur - old);
  }
  cout << cnt + maxx;

  return 0;
}
