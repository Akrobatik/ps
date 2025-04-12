// Title : 팔
// Link  : https://www.acmicpc.net/problem/1105 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string l, r;
  cin >> l >> r;
  if (l.size() != r.size()) {
    cout << "0";
    return 0;
  }

  int n = l.size();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (l[i] != r[i]) break;
    cnt += (l[i] == '8');
  }
  cout << cnt;

  return 0;
}
