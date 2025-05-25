// Title : 그거 왜 말해!
// Link  : https://www.acmicpc.net/problem/33985 
// Time  : 0 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  cout << (s[0] == 'A' && s[n - 1] == 'B' ? "Yes" : "No");

  return 0;
}