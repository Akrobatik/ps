// Title : Yut Nori
// Link  : https://www.acmicpc.net/problem/15778
// Time  : 0 ms
// Memory: 2024 KB

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

constexpr char kDelta[30][5] = {
    {5, 1, 2, 3, 4},
    {6, 2, 3, 4, 5},
    {7, 3, 4, 5, 6},
    {8, 4, 5, 6, 7},
    {9, 5, 6, 7, 8},
    {24, 21, 22, 29, 23},
    {11, 7, 8, 9, 10},
    {12, 8, 9, 10, 11},
    {13, 9, 10, 11, 12},
    {14, 10, 11, 12, 13},
    {28, 25, 26, 29, 27},
    {16, 12, 13, 14, 15},
    {17, 13, 14, 15, 16},
    {18, 14, 15, 16, 17},
    {19, 15, 16, 17, 18},
    {20, 16, 17, 18, 19},
    {-1, 17, 18, 19, 20},
    {-1, 18, 19, 20, -1},
    {-1, 19, 20, -1, -1},
    {-1, 20, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {15, 22, 29, 23, 24},
    {16, 29, 23, 24, 15},
    {18, 24, 15, 16, 17},
    {19, 15, 16, 17, 18},
    {20, 26, 29, 27, 28},
    {-1, 29, 27, 28, 20},
    {-1, 28, 20, -1, -1},
    {-1, 20, -1, -1, -1},
    {-1, 27, 28, 20, -1}};

constexpr char kCellCoords[30][2] = {
    {0, 0},
    {24, 30},
    {18, 30},
    {12, 30},
    {6, 30},
    {0, 30},
    {0, 24},
    {0, 18},
    {0, 12},
    {0, 6},
    {0, 0},
    {6, 0},
    {12, 0},
    {18, 0},
    {24, 0},
    {30, 0},
    {30, 6},
    {30, 12},
    {30, 18},
    {30, 24},
    {30, 30},
    {5, 25},
    {10, 20},
    {20, 10},
    {25, 5},
    {5, 5},
    {10, 10},
    {20, 20},
    {25, 25},
    {15, 15}};

constexpr char kNameTable[] = "ABCDabcd";

constexpr char kIdTable[] =
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\x00\x01\x02\x03\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\x04\x05\x06\x07\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff"
    "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff";

char board[] =
    R"(..----..----..----..----..----..
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
  inline int GetId() {
    return (team_id << 2) | member_idx;
  }

  inline char GetName() {
    return kNameTable[GetId()];
  }

  int team_id, member_idx;
  Cell* foothold;
};

struct Cell {
  inline bool HasEnemy(int team_id) {
    for (auto p : pieces) {
      if (p && p->team_id != team_id) return true;
    }
    return false;
  }

  Piece* pieces[4];
  Cell* next[5];
  char y, x;
};

Piece pieces[8];
Cell cells[30];

int main() {
  for (int i = 0; i < 8; i++) {
    pieces[i].team_id = i >> 2;
    pieces[i].member_idx = i & 3;
    pieces[i].foothold = cells;
  }

  for (int i = 0; i < 30; i++) {
    cells[i].y = kCellCoords[i][0];
    cells[i].x = kCellCoords[i][1];
    for (int j = 0; j < 5; j++) {
      if (kDelta[i][j] == -1) continue;;
      cells[i].next[j] = cells + kDelta[i][j];
    }
  }

  int n;
  cin >> n;
  while (n--) {
    char name;
    cin >> name;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      char c;
      cin >> c;
      if (c == 'F') ++cnt;
    }

    auto selected = pieces + kIdTable[name];
    auto src = selected->foothold;
    auto dst = src->next[cnt];
    if (dst) {
      if (dst->HasEnemy(selected->team_id)) {
        for (auto& p : dst->pieces) {
          if (p) {
            p->foothold = cells;
            p = nullptr;
          }
        }
      }

      if (src == cells) {
        dst->pieces[selected->member_idx] = selected;
        selected->foothold = dst;
      } else {
        for (int i = 0; i < 4; i++) {
          if (src->pieces[i]) {
            dst->pieces[i] = src->pieces[i];
            src->pieces[i]->foothold = dst;
            src->pieces[i] = nullptr;
          }
        }
      }
    } else {
      for (auto& p : src->pieces) {
        if (p) {
          p->foothold = nullptr;
          p = nullptr;
        }
      }
    }
  }

  for (int i = 1; i < 30; i++) {
    for (int j = 0; j < 4; j++) {
      int y = cells[i].y + (j >> 1);
      int x = cells[i].x + (j & 1);
      auto p = cells[i].pieces[j];
      board[y * 33 + x] = p ? p->GetName() : '.';
    }
  }

  cout << board;

  return 0;
}
