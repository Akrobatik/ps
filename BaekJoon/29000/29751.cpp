// Title : 삼각형
// Link  : https://www.acmicpc.net/problem/29751 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h;
  cin >> w >> h;
  int wh = w * h;
  cout << (wh >> 1) << ((wh & 1) ? ".5" : ".0");

  return 0;
}