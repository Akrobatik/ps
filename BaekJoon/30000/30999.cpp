// Title : 민주주의
// Link  : https://www.acmicpc.net/problem/30999 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int ans = 0;
  while (n--) {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      cnt += (s[i] == 'O');
    }
    ans += (cnt >= ((m + 1) >> 1));
  }
  cout << ans;

  return 0;
}
