// Title : 더하기 사이클
// Link  : https://www.acmicpc.net/problem/1110
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int Calc(int n) {
  int l = n % 10, r = (l + n / 10) % 10;
  return l * 10 + r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int nxt = Calc(n), cnt = 1;
  while (nxt != n) {
    nxt = Calc(nxt);
    ++cnt;
  }
  cout << cnt;

  return 0;
}
