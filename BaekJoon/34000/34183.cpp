// Title : SUAPC 의자 준비하기
// Link  : https://www.acmicpc.net/problem/34183 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, a, b;
  cin >> n >> m >> a >> b;

  int64_t add = n * 3 - m;
  cout << (add <= 0 ? 0 : add * a + b);

  return 0;
}
