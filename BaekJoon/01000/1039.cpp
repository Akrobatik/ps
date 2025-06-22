// Title : 교환
// Link  : https://www.acmicpc.net/problem/1039 
// Time  : 4 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  if (n == 1 || (n == 2 && s[1] == '0')) {
    cout << "-1";
    return 0;
  }

  queue<string> q;
  q.push(s);
  while (k--) {
    set<string> memo;
    int nq = q.size();
    while (nq--) {
      auto cur = q.front();
      q.pop();

      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (i == 0 && cur[j] == '0') continue;
          swap(cur[i], cur[j]);
          memo.insert(cur);
          swap(cur[i], cur[j]);
        }
      }
    }

    for (auto& e : memo) q.push(e);
  }

  s.clear();
  while (!q.empty()) {
    s = max<string>(s, q.front());
    q.pop();
  }
  cout << s;

  return 0;
}
