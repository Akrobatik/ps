// Title : 로프와 쿼리
// Link  : https://www.acmicpc.net/problem/16994 
// Time  : 220 ms
// Memory: 4000 KB

#include <bits/stdc++.h>

#include <ext/rope>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  __gnu_cxx::rope<char> rope;
  rope.append(s.c_str());

  int q;
  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    switch (cmd) {
      case 1: {
        int x, y;
        cin >> x >> y;
        auto sub = rope.substr(x, y - x + 1);
        rope.erase(x, y - x + 1);
        rope.insert(0, sub);
      } break;

      case 2: {
        int x, y;
        cin >> x >> y;
        auto sub = rope.substr(x, y - x + 1);
        rope.erase(x, y - x + 1);
        rope.insert(rope.size(), sub);
      } break;

      case 3: {
        int x;
        cin >> x;
        cout << rope[x] << "\n";
      } break;
    }
  }

  return 0;
}
