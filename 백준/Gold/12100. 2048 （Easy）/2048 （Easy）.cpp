#include <bits/stdc++.h>

using namespace std;

void Arrange(span<int> sp) {
  if (sp.size() == 0) return;
  auto it = remove(sp.begin(), sp.end(), 0);
  if (it != sp.end()) fill(it, sp.end(), 0);
  for (int i = 1; i < it - sp.begin(); i++) {
    if (sp[i - 1] == sp[i]) {
      sp[i - 1] *= 2;
      sp[i] = 0;
      Arrange(span<int>(sp.begin() + i, it));
      break;
    }
  }
}

int Solve(const vector<int>& board, int size, int depth) {
  int maxx = *max_element(board.begin(), board.end());
  if (depth == 5) return maxx;

  for (int i = 0; i < 4; i++) {
    vector<int> b(board);
    int s1 = i < 2 ? size : 1;
    int s2 = (i < 2 ? 1 : size) * (i & 1 ? -1 : 1);
    int* sp = b.data() + (i & 1 ? (size - 1) * (0 - s2) : 0);
    vector<int> tmp(size);
    for (int j = 0; j < size; j++) {
      int* p = sp + s1 * j;
      for (int k = 0; k < size; k++) tmp[k] = *(p + s2 * k);
      Arrange(tmp);
      for (int k = 0; k < size; k++) *(p + s2 * k) = tmp[k];
    }
    int v = Solve(b, size, depth + 1);
    maxx = max<int>(maxx, v);
  }

  return maxx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> board(n * n);
  int* p = board.data();
  for (int i = 0; i < n * n; i++) cin >> *p++;

  cout << Solve(board, n, 0);

  return 0;
}
