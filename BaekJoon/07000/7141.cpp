// Title : 데이터 만들기 2
// Link  : https://www.acmicpc.net/problem/7141 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << "100\n0\n";
  for (int i = 1; i < 100; i++) {
    int cnt = 10 + (i < 40);
    cout << cnt;
    for (int j = 1; j <= 10; j++) {
      cout << " " << (i + 99) % 100 << " 1";
    }
    if (cnt == 11) {
      cout << " " << (i + 1) % 100 << " -1";
    }
    cout << "\n";
  }
  cout << "10\n";
  for (int i = 0; i < 10; i++) {
    cout << "99 0\n";
  }

  return 0;
}
