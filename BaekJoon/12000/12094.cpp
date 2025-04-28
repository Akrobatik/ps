// Title : 2048 (Hard)
// Link  : https://www.acmicpc.net/problem/12094 
// Time  : 596 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

using F = bool (*)();

int ans;
int board[20][20];

bool Up() {
  bool changed = false;
  int bcopy[20];
  queue<int> q;
  for (int j = 0; j < 20; j++) {
    for (int i = 0; i < 20; i++) {
      bcopy[i] = board[i][j];
      if (board[i][j] == 0) continue;
      q.push(board[i][j]);
      board[i][j] = 0;
    }

    int i = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();

      if (board[i][j] == x) {
        board[i++][j] <<= 1;
      } else {
        if (board[i][j]) ++i;
        board[i][j] = x;
      }
    }

    for (int i = 0; !changed && i < 20; i++) {
      changed = (bcopy[i] != board[i][j]);
    }
  }
  return changed;
}

bool Down() {
  bool changed = false;
  int bcopy[20];
  queue<int> q;
  for (int j = 0; j < 20; j++) {
    for (int i = 19; i >= 0; i--) {
      bcopy[i] = board[i][j];
      if (board[i][j] == 0) continue;
      q.push(board[i][j]);
      board[i][j] = 0;
    }

    int i = 19;
    while (!q.empty()) {
      int x = q.front();
      q.pop();

      if (board[i][j] == x) {
        board[i--][j] <<= 1;
      } else {
        if (board[i][j]) --i;
        board[i][j] = x;
      }
    }

    for (int i = 0; !changed && i < 20; i++) {
      changed = (bcopy[i] != board[i][j]);
    }
  }
  return changed;
}

bool Left() {
  bool changed = false;
  int bcopy[20];
  queue<int> q;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      bcopy[j] = board[i][j];
      if (board[i][j] == 0) continue;
      q.push(board[i][j]);
      board[i][j] = 0;
    }

    int j = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();

      if (board[i][j] == x) {
        board[i][j++] <<= 1;
      } else {
        if (board[i][j]) ++j;
        board[i][j] = x;
      }
    }

    for (int j = 0; !changed && j < 20; j++) {
      changed = (bcopy[j] != board[i][j]);
    }
  }
  return changed;
}

bool Right() {
  bool changed = false;
  int bcopy[20];
  queue<int> q;
  for (int i = 0; i < 20; i++) {
    for (int j = 19; j >= 0; j--) {
      bcopy[j] = board[i][j];
      if (board[i][j] == 0) continue;
      q.push(board[i][j]);
      board[i][j] = 0;
    }

    int j = 19;
    while (!q.empty()) {
      int x = q.front();
      q.pop();

      if (board[i][j] == x) {
        board[i][j--] <<= 1;
      } else {
        if (board[i][j]) --j;
        board[i][j] = x;
      }
    }

    for (int j = 0; !changed && j < 20; j++) {
      changed = (bcopy[j] != board[i][j]);
    }
  }
  return changed;
}

F Func[4] = {Up, Down, Left, Right};

void Solve(int depth) {
  int maxx = 0;
  auto p = (int*)board;
  for (int i = 0; i < 400; i++) maxx = max<int>(maxx, *p++);
  ans = max<int>(maxx, ans);
  if (depth == 10 || (maxx << (10 - depth)) <= ans) return;

  int bcopy[20][20];
  memcpy(bcopy, board, sizeof(board));
  for (int i = 0; i < 4; i++) {
    if (Func[i]()) {
      Solve(depth + 1);
      memcpy(board, bcopy, sizeof(board));
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      ans = max<int>(ans, board[i][j]);
    }
  }
  Solve(0);
  cout << ans;

  return 0;
}
