#include <bits/stdc++.h>

using namespace std;

char m[64][64];

void Traverse(int y, int x, int n) {
  bool ok = true;
  char c = m[y][x];
  for (int i = 0; ok && i < n; i++) {
    for (int j = 0; ok && j < n; j++) {
      ok = (m[y + i][x + j] == c);
    }
  }

  if (ok) {
    cout << c;
    return;
  }

  cout << "(";
  int mid = n >> 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      Traverse(y + i * mid, x + j * mid, mid);
    }
  }
  cout << ")";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }
  Traverse(0, 0, n);

  return 0;
}
