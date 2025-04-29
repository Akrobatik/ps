// Title : 최댓값
// Link  : https://www.acmicpc.net/problem/2566 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int maxx = -1, my, mx;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      int x;
      cin >> x;
      if (maxx < x) {
        maxx = x;
        my = i, mx = j;
      }
    }
  }
  cout << maxx << "\n"
       << my << " " << mx;

  return 0;
}
