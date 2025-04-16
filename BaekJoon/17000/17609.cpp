// Title : 회문
// Link  : https://www.acmicpc.net/problem/17609 
// Time  : 12 ms
// Memory: 2552 KB

#include <bits/stdc++.h>

using namespace std;

int Check(string_view sv, bool skip) {
  int l = 0, r = sv.size() - 1;
  while (l < r) {
    if (sv[l] == sv[r]) {
      ++l, --r;
    } else {
      if (skip) {
        int sz = r - l;
        return min<int>(Check(sv.substr(l ,sz), false), Check(sv.substr(l + 1 ,sz), false));
      } else {
        return 2;
      }
    }
  }
  return 1 - skip;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << Check(s, true) << "\n";
  }

  return 0;
}
