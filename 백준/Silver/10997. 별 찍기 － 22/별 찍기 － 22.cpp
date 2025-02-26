#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n == 1) {
    cout << "*";
    return 0;
  }

  int h = (n << 2) - 1, w = h - 2;
  int ch = h >> 1, cw = w >> 1;
  vector<vector<char>> m(h, vector<char>(w, ' '));
  m[ch - 1][cw] = m[ch][cw] = m[ch + 1][cw] = '*';
  for (int i = 1; i < n; i++) {
    int dx = i << 1, dy = dx + 1;
    for (int j = -dy; j <= dy; j++) {
      m[ch + j][cw - dx] = m[ch + j][cw + dx] = '*';
    }
    for (int j = -dx; j <= dx; j++) {
      m[ch - dy][cw + j] = m[ch + dy][cw + j] = '*';
    }
    m[ch - dy + 1][cw + dx] = ' ';
    m[ch - dy + 2][cw + dx - 1] = '*';
  }

  for (auto& row : m) {
    string s;
    s.resize(w);
    for (int i = 0; i < w; i++) s[i] = row[i];
    s.resize(s.find_last_not_of(' ') + 1);
    cout << s << "\n";
  }

  return 0;
}
