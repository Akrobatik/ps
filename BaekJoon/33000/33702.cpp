// Title : 비밀번호
// Link  : https://www.acmicpc.net/problem/33702
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;
  switch (k) {
    case 1:
    case 3:
    case 7:
    case 9: {
      cout << "8";
    } break;
    case 2:
    case 4:
    case 6:
    case 8: {
      cout << "0";
    } break;

    case 5: {
      cout << "8";
    } break;
  }

  return 0;
}
