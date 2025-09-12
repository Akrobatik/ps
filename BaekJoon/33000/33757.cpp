// Title : 논리 연산과 쿼리
// Link  : https://www.acmicpc.net/problem/33757 
// Time  : 32 ms
// Memory: 5008 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<int> memo(n), sz(n, 1);
  iota(memo.begin(), memo.end(), 0);

  for (int i = 1; i < n; i++) {
    int op = (i << 1) - 1;
    if (s[op] == '&') {
      memo[i] = memo[i - 1];
      ++sz[memo[i]];
    }
  }

  int all = 0;
  for (int i = 0; i < n; i++) all += (memo[i] == i);

  int on = 0;
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    if (s[i << 1] == '0') continue;
    int id = memo[i];
    if (++cnt[id] == sz[id]) ++on;
  }

  while (q--) {
    int i;
    cin >> i;

    int id = memo[i - 1];
    i = (i - 1) << 1;
    s[i] ^= 1;
    if (s[i] == '0') {
      if (cnt[id]-- == sz[id]) --on;
    } else {
      if (++cnt[id] == sz[id]) ++on;
    }
    cout << (on ? '1' : '0');
  }

  return 0;
}
