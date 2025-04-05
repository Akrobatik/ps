// Title : 조합 0의 개수
// Link  : https://www.acmicpc.net/problem/2004
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int Count(int n, int m) {
  int cnt = 0;
  while (n) cnt += n / m, n /= m;
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int c2 = Count(n, 2) - Count(n - m, 2) - Count(m, 2);
  int c5 = Count(n, 5) - Count(n - m, 5) - Count(m, 5);
  cout << min<int>(c2, c5);

  return 0;
}
