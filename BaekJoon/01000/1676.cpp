// Title : 팩토리얼 0의 개수
// Link  : https://www.acmicpc.net/problem/1676
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
  while (n /= 5) cnt += n;
  cout << cnt;

  return 0;
}
