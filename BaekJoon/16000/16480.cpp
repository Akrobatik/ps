// Title : 외심과 내심은 사랑입니다
// Link  : https://www.acmicpc.net/problem/16480 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;
  cout << (a - b) * (a - b) - b * b;

  return 0;
}
