// Title : 꼬마 미타
// Link  : https://www.acmicpc.net/problem/34923 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int Read() {
  int hh, mm;
  char c;
  cin >> hh >> c >> mm;
  return (hh - 1) * 60 + mm;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x = Read(), y = Read();
  if (x > y) swap(x, y);
  int dt = min<int>(y - x, x + 720 - y);
  cout << dt * 6;

  return 0;
}