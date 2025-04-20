// Title : Stone Jump
// Link  : https://www.acmicpc.net/problem/33788 
// Time  : 0 ms
// Memory: 2648 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    if (n == 1 || (s.front() != 'L' || s.back() != 'R')) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
