// Title : 레퓨닛의 덧셈
// Link  : https://www.acmicpc.net/problem/33964 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;
  cin >> x >> y;
  string s1(x, '1'), s2(y, '1');
  cout << stoi(s1) + stoi(s2);

  return 0;
}
