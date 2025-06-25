// Title : /gg
// Link  : https://www.acmicpc.net/problem/34032 
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
  int half = (n + 1) >> 1;
  cout << (count(s.begin(), s.end(), 'O') >= half ? "Yes" : "No");

  return 0;
}
