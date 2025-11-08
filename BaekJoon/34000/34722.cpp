// Title : 출제자가 몇 명
// Link  : https://www.acmicpc.net/problem/34722 
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
  while (n--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cnt += (a >= 1000 || b >= 1600 || c >= 1500 || (1 <= d && d <= 30));
  }
  cout << cnt;

  return 0;
}