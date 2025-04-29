// Title : 키로거
// Link  : https://www.acmicpc.net/problem/5397 
// Time  : 252 ms
// Memory: 19384 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    list<char> ans;
    auto it = ans.begin();
    for (auto c : s) {
      switch (c) {
        case '<': {
          if (it != ans.begin()) --it;
        } break;
        case '>': {
          if (it != ans.end()) ++it;
        } break;
        case '-': {
          if (it != ans.begin()) it = ans.erase(--it);
        } break;
        default: {
          it = ans.insert(it, c);
          ++it;
        } break;
      }
    }

    for (auto c : ans) cout << c;
    cout << "\n";
  }

  return 0;
}
