// Title : 칸토어 집합
// Link  : https://www.acmicpc.net/problem/4779 
// Time  : 0 ms
// Memory: 2660 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n) {
    int m = 1;
    while (n--) m *= 3;
    
    string s(m, ' ');
    s[0] = '-';
    int cur = 1;
    while (cur != m) {
      int nxt = cur * 3;
      copy(s.begin(), s.begin() + cur, s.begin() + nxt - cur);
      cur = nxt;
    }
    cout << s << "\n";
  }

  return 0;
}
