#include <bits/stdc++.h>

using namespace std;

constexpr char kBoard[] = R"(..----..----..----..----..----..
..    ..    ..    ..    ..    ..
| \                          / |
|  \                        /  |
|   \                      /   |
|    ..                  ..    |
..   ..                  ..   ..
..     \                /     ..
|       \              /       |
|        \            /        |
|         ..        ..         |
|         ..        ..         |
..          \      /          ..
..           \    /           ..
|             \  /             |
|              ..              |
|              ..              |
|             /  \             |
..           /    \           ..
..          /      \          ..
|         ..        ..         |
|         ..        ..         |
|        /            \        |
|       /              \       |
..     /                \     ..
..   ..                  ..   ..
|    ..                  ..    |
|   /                      \   |
|  /                        \  |
| /                          \ |
..    ..    ..    ..    ..    ..
..----..----..----..----..----..)";

struct Cell;

struct Piece {
  Piece() : id(0), foothold(nullptr) {}

  char GetName() {
    return GetTeamId() * 32 + GetMemberId() + 'A';
  }

  int GetTeamId() {
    return id / 4;
  }

  int GetMemberId() {
    return id % 4;
  }

  bool IsEnemy(Piece* other) {
    return GetTeamId() != other->GetTeamId();
  }

  void Move(int steps, Cell* root);

  char id;
  Cell* foothold;
};

struct Cell {
  Cell() : x(0), y(0) {
    for (int i = 0; i < 4; i++) pieces[i] = nullptr;
    for (int i = 0; i < 5; i++) next[i] = nullptr;
  }

  bool HasEnemy(int team_id) {
    for (auto piece : pieces) {
      if (piece && piece->GetTeamId() != team_id) return true;
    }
    return false;
  }

  void Print(string& board) {
    for (int i = 0; i < 4; i++) {
      int yy = y + i / 2;
      int xx = x + i % 2;
      board[yy * 33 + xx] = pieces[i] ? pieces[i]->GetName() : '.';
    }
  }

  void MoveTo(Piece* leader, Cell* dst, Cell* root) {
    if (dst->HasEnemy(leader->GetTeamId())) {
      for (int i = 0; i < 4; i++) {
        if (dst->pieces[i]) dst->pieces[i]->foothold = root;
        dst->pieces[i] = nullptr;
      }
    }

    if (this == root) {
      dst->pieces[leader->GetMemberId()] = leader;
      leader->foothold = dst;
      return;
    }

    for (int i = 0; i < 4; i++) {
      if (pieces[i]) pieces[i]->foothold = dst;
    }

    for (int i = 0; i < 4; i++) {
      dst->pieces[i] = pieces[i];
      pieces[i] = nullptr;
    }
  }

  int y, x;
  Piece* pieces[4];
  Cell* next[5];
};

void Piece::Move(int steps, Cell* root) {
  auto src = foothold;
  auto dst = src->next[steps - 1];
  if (dst) {
    src->MoveTo(this, dst, root);
  } else {
    for (auto piece : src->pieces) {
      if (piece) {
        piece->foothold = nullptr;
        piece = nullptr;
      }
    }
  }
}

struct Board {
  Board() : board(kBoard) {
    Init();
  }

  void Init() {
    for (int i = 0; i < 8; i++) {
      pieces[i].id = i;
      pieces[i].foothold = cells;
    }

    // xy
    for (int i = 0; i < 5; i++) {
      cells[5 - i].y = i * 6;
      cells[5 - i].x = 30;

      cells[10 + i].y = i * 6;
      cells[10 + i].x = 0;
    }

    for (int i = 0; i < 6; i++) {
      cells[15 + i].y = 30;
      cells[15 + i].x = i * 6;
    }

    for (int i = 0; i < 4; i++) {
      cells[6 + i].y = 0;
      cells[6 + i].x = 24 - i * 6;
    }

    for (int i = 0; i < 2; i++) {
      cells[21 + i].y = i * 5 + 5;
      cells[21 + i].x = 25 - i * 5;

      cells[23 + i].y = i * 5 + 20;
      cells[23 + i].x = 10 - i * 5;

      cells[25 + i].y = i * 5 + 5;
      cells[25 + i].x = i * 5 + 5;

      cells[27 + i].y = i * 5 + 20;
      cells[27 + i].x = i * 5 + 20;
    }

    cells[29].y = 15;
    cells[29].x = 15;

    // next
    for (int i = 0; i < 20; i++) {
      if (i == 5 || i == 10) continue;
      for (int j = 0; j < 5 && i + j < 20; j++) {
        cells[i].next[j] = cells + i + j + 1;
      }
    }

    vector<Cell*> vec;
    vec.reserve(11);
    vec.push_back(cells + 5);
    for (int i = 0; i < 2; i++) vec.push_back(cells + i + 21);
    vec.push_back(cells + 29);
    for (int i = 0; i < 2; i++) vec.push_back(cells + i + 23);
    for (int i = 0; i < 5; i++) vec.push_back(cells + i + 15);
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 5; j++) {
        vec[i]->next[j] = vec[i + j + 1];
      }
    }

    vec.clear();
    vec.push_back(cells + 10);
    for (int i = 0; i < 2; i++) vec.push_back(cells + i + 25);
    vec.push_back(cells + 29);
    for (int i = 0; i < 2; i++) vec.push_back(cells + i + 27);
    vec.push_back(cells + 20);
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 5 && i + j < 6; j++) {
        vec[i]->next[j] = vec[i + j + 1];
      }
    }

    cells[29].next[0] = cells + 27;
    cells[29].next[1] = cells + 28;
    cells[29].next[2] = cells + 20;
    cells[29].next[3] = cells[29].next[4] = nullptr;
  }

  void Input() {
    auto piece = InputPiece();
    int steps = InputSteps();
    piece->Move(steps, cells);
  }

  void Print() {
    for (int i = 1; i < 30; i++) cells[i].Print(board);
    cout << board;
  }

  Piece* InputPiece() {
    char c;
    cin >> c;
    if (c < 'a') return pieces + (c - 'A');
    return pieces + (c - 'a' + 4);
  }

  int InputSteps() {
    char s[8];
    cin >> s;
    int steps = 4;
    for (int i = 0; i < 4; i++) {
      if (s[i] == 'B') --steps;
    }
    return steps ? steps : 5;
  }

  string board;
  Cell cells[30];
  Piece pieces[8];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Board board;
  int n;
  cin >> n;
  while (n--) board.Input();
  board.Print();

  return 0;
}
