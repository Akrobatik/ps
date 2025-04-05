// Title : 1과 5
// Link  : https://www.acmicpc.net/problem/33615
// Time  : 4 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    int n = s.size();
    int cnt = 0;
    bool b1 = false, b5 = false;
    for (char c : s) {
      if (c == '1') {
        ++cnt;
        b1 = true;
      } else {
        cnt += 2;
        b5 = true;
      }
    }

    int rem = cnt % 3;
    if (rem == 0) {
      cout << "0 3\n";
    } else if (rem == 1) {
      if (b1) {
        cout << (s.find_first_of('1') + 1) << " 3\n";
      } else {
        cout << (n & 1) << " 11\n";
      }
    } else {
      if (b5) {
        cout << (s.find_first_of('5') + 1) << " 3\n";
      } else {
        cout << (n & 1) << " 11\n";
      }
    }
  }

  return 0;
}
