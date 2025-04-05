// Title : 설탕 배달
// Link  : https://www.acmicpc.net/problem/2839
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i < 5; i++) {
    if (n % 5 == 0) break;
    n -= 3;
    ++cnt;
  }

  if (n < 0) {
    cout << -1;
  } else {
    cout << n / 5 + cnt;
  }

  return 0;
}
