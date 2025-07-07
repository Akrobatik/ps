// Title : 직사각형에서 탈출
// Link  : https://www.acmicpc.net/problem/1085 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, w, h;
  cin >> x >> y >> w >> h;
  cout << min<int>({x, w - x, y, h - y});

  return 0;
}
