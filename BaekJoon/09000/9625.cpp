// Title : BABBA
// Link  : https://www.acmicpc.net/problem/9625 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t cnt[2] = {0, 1};
  for (int i = 1; i < n; i++) {
    int64_t a = cnt[1], b = cnt[0] + cnt[1];
    cnt[0] = a, cnt[1] = b;
  }
  cout << cnt[0] << " " << cnt[1];
  
  return 0;
}
