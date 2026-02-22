// Title : 팩토리얼 0의 개수
// Link  : https://www.acmicpc.net/problem/11687 
// Time  : 108 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int cur = 0;
  for (int i = 5; cur < n; i += 5) {
    int x = i;
    do ++cur, x /= 5;
    while (x % 5 == 0);

    if (cur == n) cout << i;
  }
  if (cur != n) cout << "-1";

  return 0;
}