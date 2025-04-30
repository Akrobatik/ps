// Title : 알파벳 다이아몬드
// Link  : https://www.acmicpc.net/problem/1262 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

char GetChar(int n, int y, int x) {
  int sz = (n << 1) - 1;
  y %= sz, x %= sz;
  int dy = abs(n - 1 - y), dx = abs(n - 1 - x);
  if (dy + dx >= n) return '.';
  return 'a' + (dy + dx) % 26;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, r1, c1, r2, c2;
  cin >> n >> r1 >> c1 >> r2 >> c2;
  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++) {
      cout << GetChar(n, i, j);
    }
    cout << "\n";
  }

  return 0;
}
