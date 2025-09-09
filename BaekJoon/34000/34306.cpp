// Title : M-Climb Road
// Link  : https://www.acmicpc.net/problem/34306 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, n;
  cin >> w >> n;
  w *= 5280;

  cout << w / n;

  return 0;
}
