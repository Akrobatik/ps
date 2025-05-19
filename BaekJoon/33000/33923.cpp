// Title : 인경호 울타리 공사
// Link  : https://www.acmicpc.net/problem/33923 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);

  --n, --m;
  if (n == m) {
    cout << (n - 1) * (n - 1) + 1;
  } else {
    cout << n * n;
  }

  return 0;
}
