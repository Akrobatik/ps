// Title : 쿼드 트리
// Link  : https://www.acmicpc.net/problem/6580 
// Time  : 4 ms
// Memory: 2280 KB

#include <bits/stdc++.h>

using namespace std;

char board[512][512];

bool Check(int y, int x, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[y][x] == board[y + i][x + j]) continue;
      return false;
    }
  }
  return true;
}

void Traverse(int y, int x, int n) {
  if (Check(y, x, n)) {
    cout << (board[y][x] ? 'B' : 'W');
  } else {
    cout << 'Q';
    n >>= 1;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        Traverse(y + n * i, x + n * j, n);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> s >> s >> n >> s >> s >> s >> s >> s >> s >> s >> s;

  int m = (n + 7) / 8;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      getline(cin, s, ',');
      int x = stoi(s, 0, 16);
      bitset<32> bits(x);
      for (int k = 0; k < 8; k++) {
        board[i][(j << 3) + k] = bits.test(k);
      }
    }
  }
  cout << n << "\n";
  Traverse(0, 0, n);

  return 0;
}
