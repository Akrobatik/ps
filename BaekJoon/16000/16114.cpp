// Title : 화살표 연산자
// Link  : https://www.acmicpc.net/problem/16114 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n;
  cin >> x >> n;

  if (n != 1 && (n & 1)) {
    cout << "ERROR";
    return 0;
  }

  if (n == 1) x = -x, n = 0;

  int cnt = 0;
  while ((x -= (n >> 1)) > 0 && cnt < 1000) ++cnt;

  if (cnt == 1000) {
    cout << "INFINITE";
  } else {
    cout << cnt;
  }

  return 0;
}
