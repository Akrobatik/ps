// Title : 새로운 달력 (Small)
// Link  : https://www.acmicpc.net/problem/12437 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int Calc(int a, int b, int c) {
  int res = 0, x = 0;
  for (int i = 0; i < a; i ++) {
    res += (b + x) / c;
    if ((b + x) % c == 0) {
      x = 0;
    } else {
      ++res;
      x = (b + x) % c;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << "Case #" << i << ": " << Calc(a, b, c) << "\n";
  }

  return 0;
}
