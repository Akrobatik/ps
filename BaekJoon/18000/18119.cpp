// Title : 단어 암기
// Link  : https://www.acmicpc.net/problem/18119 
// Time  : 152 ms
// Memory: 3964 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  vector<vector<int>> links(26);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    bool vis[26] = {};
    for (auto c : s) vis[c - 'a'] = true;
    for (int j = 0; j < 26; j++) {
      if (vis[j]) links[j].push_back(i);
    }
  }

  uint8_t act[26] = {};

  int cnt = n;
  while (m--) {
    char cmd, x;
    cin >> cmd >> x;
    x -= 'a';
    if ((cmd == '1') == (act[x] == 0)) {
      act[x] ^= 1;
      int dt = (cmd == '1') ? 1 : -1;
      for (auto e : links[x]) {
        int old = (arr[e] == 0);
        arr[e] += dt;
        int cur = (arr[e] == 0);
        cnt += cur - old;
      }
    }
    cout << cnt << "\n";
  }

  return 0;
}