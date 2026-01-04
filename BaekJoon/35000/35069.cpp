// Title : Atlantic Email
// Link  : https://www.acmicpc.net/problem/35069 
// Time  : 8 ms
// Memory: 13820 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string cmd;
  cin >> cmd;
  if (cmd[0] == 's') {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> msg(5, vector<int>(n + 5));
    for (int i = 0; i < 5; i++) msg[i][i] = 1;

    for (int i = 0; i < n; i++) {
      int x = s[i] - 'a';
      for (int j = 0; j < 5; j++) {
        msg[j][i + 5] = (x >> j) & 1;
      }
    }

    for (auto arr : msg) {
      for (auto e : arr) cout << e;
      cout << "\n";
    }
  } else {
    vector<string> msg(5);
    for (auto& e : msg) cin >> e;
    sort(msg.begin(), msg.end(), greater<string>());

    int n = msg[0].size() - 5;
    string res(n, 'a');
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        if (msg[j][i + 5] == '1') res[i] += 1 << j;
      }
    }
    cout << res;
  }

  return 0;
}