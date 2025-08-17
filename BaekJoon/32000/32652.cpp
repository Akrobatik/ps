// Title : 아카라카 2
// Link  : https://www.acmicpc.net/problem/32652 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string s = "AKA";
  s.reserve(n * 4 + 3);
  while (n--) {
    s.append("RAKA");
  }
  cout << s;

  return 0;
}
