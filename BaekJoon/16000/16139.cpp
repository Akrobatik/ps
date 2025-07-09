// Title : 인간-컴퓨터 상호작용
// Link  : https://www.acmicpc.net/problem/16139 
// Time  : 92 ms
// Memory: 22716 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  vector<array<int, 26>> arr(n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      arr[i + 1][j] = arr[i][j] + (s[i] - 'a' == j);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    char c;
    int l, r;
    cin >> c >> l >> r;
    int ci = c - 'a';
    cout << arr[r + 1][ci] - arr[l][ci] << "\n";
  }

  return 0;
}
