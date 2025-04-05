// Title : 종이의 개수
// Link  : https://www.acmicpc.net/problem/1780
// Time  : 328 ms
// Memory: 6692 KB

#include <bits/stdc++.h>

using namespace std;

int n;
int8_t board[2187][2187];
int memo[3];

void Traverse(int y, int x, int dv) {
  bool ok = true;
  int nn = n / dv;
  int8_t v = board[y][x];
  for (int i = 0; ok && i < nn; i++) {
    for (int j = 0; ok && j < nn; j++) {
      if (board[y + i][x + j] == v) continue;
      ok = false;
    }
  }

  if (ok) {
    ++memo[v + 1];
    return;
  }

  dv *= 3;
  nn /= 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Traverse(y + nn * i, x + nn * j, dv);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v;
      cin >> v;
      board[i][j] = v;
    }
  }

  Traverse(0, 0, 1);

  for (int i = 0; i < 3; i++) cout << memo[i] << "\n";

  return 0;
}
