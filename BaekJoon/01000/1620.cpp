// Title : 나는야 포켓몬 마스터 이다솜
// Link  : https://www.acmicpc.net/problem/1620
// Time  : 160 ms
// Memory: 20868 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  map<string, int> mp;
  vector<string> names(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> names[i];
    mp.insert({names[i], i});
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if ('1' <= s[0] && s[0] <= '9') {
      cout << names[stoi(s)] << "\n";
    } else {
      cout << mp[s] << "\n";
    }
  }

  return 0;
}
