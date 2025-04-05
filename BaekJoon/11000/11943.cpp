// Title : 파일 옮기기
// Link  : https://www.acmicpc.net/problem/11943
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a0, b0, a1, b1;
  cin >> a0 >> b0 >> a1 >> b1;
  cout << min<int64_t>(a0 + b1, a1 + b0);

  return 0;
}
