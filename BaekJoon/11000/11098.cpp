// Title : 첼시를 도와줘！
// Link  : https://www.acmicpc.net/problem/11098
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    int maxx = INT_MIN;
    while (n--) {
      int c;
      string ss;
      cin >> c >> ss;
      if (maxx < c) maxx = c, s.swap(ss);
    }
    cout << s << "\n";
  }

  return 0;
}
