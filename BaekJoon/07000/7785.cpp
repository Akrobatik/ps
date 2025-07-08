// Title : 회사에 있는 사람
// Link  : https://www.acmicpc.net/problem/7785 
// Time  : 76 ms
// Memory: 9948 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  set<string, greater<string>> hs;
  int n;
  cin >> n;
  while (n--) {
    string s, cmd;
    cin >> s >> cmd;
    if (cmd[0] == 'e') {
      hs.insert(s);
    } else {
      hs.erase(s);
    }
  }
  for (auto& s : hs) cout << s << "\n";

  return 0;
}
