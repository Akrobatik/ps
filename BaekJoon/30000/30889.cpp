// Title : 좌석 배치도
// Link  : https://www.acmicpc.net/problem/30889 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> mat(10, string(20, '.'));

  int n;
  cin >> n;
  while (n--) {
    char cy;
    int x;
    cin >> cy >> x, --x;
    int y = cy - 'A';
    mat[y][x] = 'o';
  }

  for (auto& s : mat) cout << s << "\n";

  return 0;
}