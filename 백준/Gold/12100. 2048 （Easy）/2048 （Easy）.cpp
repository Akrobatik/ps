#include <bits/stdc++.h>

using namespace std;

struct Board {
  Board(int n) : size(n), m(n * n) {}

  int* operator[](int row) { return m.data() + row * size; }

  int size;
  vector<int> m;
};

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

int Solve(const Board& board, int depth) {
  int maxx = *max_element(board.m.begin(), board.m.end());
  if (depth == 5) return maxx;

  for (int i = 0; i < 4; i++) {
    Board b(board);
    int s1 = i < 2 ? board.size : 1;
    int s2 = (i < 2 ? 1 : board.size) * (i & 1 ? -1 : 1);
    int* sp = b.m.data() + (i == 1 ?  board.size - 1 : i == 3 ? board.size * (board.size - 1) : 0);
    vector<int> vec(board.size);
    for (int j = 0; j < board.size; j++) {
      int* p = sp + s1 * j;
      for (int k = 0; k < board.size; k++) vec[k] = *(p + s2 * k);
      Arrange(vec);
      for (int k = 0; k < board.size; k++) *(p + s2 * k) = vec[k];
    }
    int v = Solve(b, depth + 1);
    maxx = max<int>(maxx, v);
  }

  return maxx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  Board board(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> board[i][j];
  }

  cout << Solve(board, 0);

  return 0;
}
