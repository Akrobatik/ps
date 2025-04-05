// Title : 숫자의 합
// Link  : https://www.acmicpc.net/problem/11720
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int ans = 0;
  while (n--) {
    char c;
    cin >> c;
    ans += (c - '0');
  }
  cout << ans;

  return 0;
}
