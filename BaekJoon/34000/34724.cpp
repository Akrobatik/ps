// Title : 종양 찾기
// Link  : https://www.acmicpc.net/problem/34724 
// Time  : 8 ms
// Memory: 3100 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, -1}, {-1, 0}, {0, -1}, {0, 0}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> mat(n);
  for (auto& s : mat) {
    cin >> s;
    for (auto& c : s) c ^= '0';
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int cnt = 0;
      for (auto [dy, dx] : kDelta) {
        cnt += mat[i + dy][j + dx];
      }
      if (cnt == 4) {
        cout << "1";
        return 0;
      }
    }
  }
  cout << "0";

  return 0;
}