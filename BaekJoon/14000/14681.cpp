// Title : 사분면 고르기
// Link  : https://www.acmicpc.net/problem/14681 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;
  cin >> x >> y;
  if (x > 0 && y > 0) {
    cout << 1;
  } else if (x > 0 && y < 0) {
    cout << 4;
  } else if (x < 0 && y > 0) {
    cout << 2;
  } else {
    cout << 3;
  }

  return 0;
}
