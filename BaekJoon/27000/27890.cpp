// Title : 특별한 작은 분수
// Link  : https://www.acmicpc.net/problem/27890 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n;
  cin >> x >> n;
  while (n--) {
    if (x & 1) {
      x = (x << 1) ^ 6;
    } else {
      x = (x >> 1) ^ 6;
    }
  }
  cout << x;

  return 0;
}
