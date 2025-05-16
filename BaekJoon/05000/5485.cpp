// Title : 평균값 수열
// Link  : https://www.acmicpc.net/problem/5485 
// Time  : 528 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int l = -2000000000, r = 2000000000;
  while (n-- && l <= r) {
    int x;
    cin >> x;
    r = min<int>(r, x);
    x <<= 1;
    tie(l, r) = make_pair(x - r, x - l);
  }
  cout << max<int>(r - l + 1, 0);

  return 0;
}
