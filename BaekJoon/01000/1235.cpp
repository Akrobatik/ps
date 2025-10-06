// Title : 학생 번호
// Link  : https://www.acmicpc.net/problem/1235 
// Time  : 0 ms
// Memory: 2316 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<string> strs(n);
  for (auto& s : strs) {
    cin >> s;
    reverse(s.begin(), s.end());
  }

  for (int len = 1;; len++) {
    unordered_set<string> hs;
    bool ok = true;
    for (auto& s : strs) {
      string pre = s.substr(0, min<int>(len, s.size()));
      if (hs.contains(pre)) {
        ok = false;
        break;
      }
      hs.insert(pre);
    }

    if (ok) {
      cout << len;
      break;
    }
  }

  return 0;
}