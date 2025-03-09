#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {0, -1},
    {0, 0},
    {0, 1},
    {1, 0}};

int ans = INT_MAX;
bitset<10> m[10];

void Switch(int y, int x) {
  for (auto [dy, dx] : kDelta) {
    int yy = y + dy, xx = x + dx;
    if (0 <= yy && yy < 10 && 0 <= xx && xx < 10) {
      m[yy][xx].flip();
    }
  }
}

void Traverse(int y, int cnt) {
  if (ans <= cnt) return;

  if (y == 10) {
    if (m[9].none()) ans = min<int>(ans, cnt);
    return;
  }

  bitset<10> bits = m[y - 1];
  for (int i = 0; i < 10; i++) {
    if (bits[i]) Switch(y, i);
  }
  Traverse(y + 1, cnt + bits.count());
  for (int i = 0; i < 10; i++) {
    if (bits[i]) Switch(y, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char s[12];
  for (int i = 0; i < 10; i++) {
    cin >> s;
    for (int j = 0; j < 10; j++) {
      m[i][j] = (s[j] == 'O');
    }
  }

  for (int j = 0; j < 1024; j++) {
    bitset<10> bits(j);
    for (int i = 0; i < 10; i++) {
      if (bits[i]) Switch(0, i);
    }
    Traverse(1, bits.count());
    for (int i = 0; i < 10; i++) {
      if (bits[i]) Switch(0, i);
    }
  }

  cout << (ans != INT_MAX ? ans : -1);

  return 0;
}
