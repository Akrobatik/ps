// Title : 중복된 숫자
// Link  : https://www.acmicpc.net/problem/15719 
// Time  : 1588 ms
// Memory: 11664 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool check[10000001] = {};

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    if (check[x]) {
      cout << x;
      return 0;
    }
    check[x] = true;
  }

  return 0;
}