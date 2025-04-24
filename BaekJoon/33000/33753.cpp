// Title : 주차 요금 정산하기
// Link  : https://www.acmicpc.net/problem/33753 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, t;
  cin >> a >> b >> c >> t;
  t -= 30;

  if (t <= 0) {
    cout << a;
  } else {
    cout << a + ((t + b - 1) / b) * c;
  }

  return 0;
}
