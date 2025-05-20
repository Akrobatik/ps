// Title : 2025 만들기
// Link  : https://www.acmicpc.net/problem/33892 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n <= 6) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";

  int cnt = 0;
  while (n - 2 >= 7) {
    cout << n << " - " << n - 1 << "\n";
    n -= 2, ++cnt;
  }
  if ((n & 1) == 0) cout << "8 - 4\n";
  cout << "1 + 4\n"
          "5 * 5\n"
          "2 + 7\n"
          "3 + 6\n"
          "9 * 9\n"
          "81 * 25\n";
  while (cnt--) cout << "2025 * 1\n";

  return 0;
}