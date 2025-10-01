// Title : Вася и Циклические Сдвиги
// Link  : https://www.acmicpc.net/problem/30845 
// Time  : 104 ms
// Memory: 51296 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size(), m = n << 1;
  s += s;

  int ans = 0, i = 0;
  while (i < n) {
    int j = i + 1, k = i;
    while (j < m && s[j] >= s[k]) {
      if (s[j++] != s[k++]) k = i;
    }

    int step = j - k;
    int nxt = i + (j - i) / step * step;
    int ub = min<int>(n - 1, nxt);
    ans = (ub - i) / step + 1;
    i = nxt;
  }
  cout << ans;

  return 0;
}