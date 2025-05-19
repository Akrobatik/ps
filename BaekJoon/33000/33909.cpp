// Title : 알파벳 블록
// Link  : https://www.acmicpc.net/problem/33909 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int s, c, o, n;
  cin >> s >> c >> o >> n;

  int ss = s + n;
  int cc = c + (o << 1);
  cout << min<int>(ss / 3, cc / 6);

  return 0;
}