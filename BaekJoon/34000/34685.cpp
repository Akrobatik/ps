// Title : 이차 방정식
// Link  : https://www.acmicpc.net/problem/34685 
// Time  : 84 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t k;
  cin >> k;

  int64_t ak = abs(k);

  int64_t cnt = 0;
  for (int64_t i = 0; i < ak; i++) {
    if ((i * i) % (ak - i) == 0) cnt += 2;
  }
  cout << cnt << " " << k * cnt * 2;

  return 0;
}