// Title : 주니어 개발자 동우의 직행 취업일기
// Link  : https://www.acmicpc.net/problem/35152 
// Time  : 100 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n % 2 == 0) {
    int m = n / 2;
    cout << m + 4 << "\n"
         << "1 3\n"
         << "2 3\n"
         << "3 4\n";
    for (int i = 1; i <= m; i++) {
      cout << "4 " << i + 4 << "\n";
    }
  } else if (n % 3 == 0) {
    int m = n / 3;
    cout << m + 5 << "\n"
         << "1 4\n"
         << "2 4\n"
         << "3 4\n"
         << "4 5\n";
    for (int i = 1; i <= m; i++) {
      cout << "5 " << i + 5 << "\n";
    }
  } else {
    cout << n + 3 << "\n"
         << "1 2\n"
         << "2 3\n";
    for (int i = 1; i <= n; i++) {
      cout << "3 " << i + 3 << "\n";
    }
  }

  return 0;
}