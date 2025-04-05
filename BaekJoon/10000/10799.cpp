// Title : 쇠막대기
// Link  : https://www.acmicpc.net/problem/10799
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char str[100001];
  cin >> str;
  int64_t ans = 0;
  int cnt = 0;
  for (auto ptr = str; *ptr; ++ptr) {
    if (*ptr == '(') {
      ++cnt;
    } else {
      --cnt;
      if (*(ptr - 1) == '(') {
        ans += cnt;
      } else {
        ++ans;
      }
    }
  }
  cout << ans;

  return 0;
}
