// Title : 빙고
// Link  : https://www.acmicpc.net/problem/17106
// Time  : 0 ms
// Memory: 4528 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int limit = 1 << 25;
  for (int b = 0; b < limit; b++) {
    bitset<25> bits(b), bingo(0);

    auto Get = [&](int y, int x) {
      return bits.test(y * 5 + x);
    };

    auto CheckR = [&](int r) {
      for (int i = 0; i < 5; i++) {
        if (!Get(r, i)) return false;
      }
      return true;
    };

    auto CheckC = [&](int c) {
      for (int i = 0; i < 5; i++) {
        if (!Get(i, c)) return false;
      }
      return true;
    };

    auto CheckDA = [&]() {
      for (int i = 0; i < 5; i++) {
        if (!Get(i, i)) return false;
      }
      return true;
    };

    auto CheckDB = [&]() {
      for (int i = 0; i < 5; i++) {
        if (!Get(i, 4 - i)) return false;
      }
      return true;
    };

    for (int i = 0; i < 5; i++) {
      if (CheckR(i)) {
        for (int j = 0; j < 5; j++) bingo.set(i * 5 + j);
      }
      if (CheckC(i)) {
        for (int j = 0; j < 5; j++) bingo.set(j * 5 + i);
      }
    }
    if (CheckDA()) {
      for (int i = 0; i < 5; i++) bingo.set(i * 5 + i);
    }
    if (CheckDB()) {
      for (int i = 0; i < 5; i++) bingo.set(i * 5 + 4 - i);
    }

    // A1
    {
      bool me = Get(0, 0);
      bool cond = !CheckDB();
      if (me != cond) continue;
    }

    // A2
    {
      bool me = Get(1, 0);
      bool cond = !Get(3, 0);
      if (me != cond) continue;
    }

    // A3
    {
      bool me = Get(2, 0);
      bool cond = CheckR(2) || CheckC(0);
      if (me != cond) continue;
    }

    // A4
    {
      bool me = Get(3, 0);
      bool cond = !Get(1, 0);
      if (me != cond) continue;
    }

    // A5
    {
      bool me = Get(4, 0);
      bool cond = Get(4, 4);
      if (me != cond) continue;
    }

    // B1
    {
      bool me = Get(0, 1);
      bool cond = !(CheckR(0) || CheckC(1));
      if (me != cond) continue;
    }

    // B2
    {
      bool me = Get(1, 1);
      bool c1 = false, c2 = false, c3 = (CheckDA() || CheckDB());
      for (int i = 0; i < 5; i++) {
        c1 |= CheckR(i);
        c2 |= CheckC(i);
      }

      bool cond = c1 && c2 && c3;
      if (me != cond) continue;
    }

    // B3
    {
      bool me = Get(2, 1);
      int cnt = bits.count() - bingo.count();
      bool cond = (cnt >= 5);
      if (me != cond) continue;
    }

    // B4
    {
      bool me = Get(3, 1);
      bool cond = CheckR(1) || CheckC(3);
      if (me != cond) continue;
    }

    // B5
    {
      // output 보고 판단
    }

    // C1
    {
      bool me = Get(0, 2);
      bool cond = CheckDA();
      if (me != cond) continue;
    }

    // C2
    {
      bool me = Get(1, 2);
      bool cond = true;
      if (me != cond) continue;
    }

    // C3
    {
      bool me = Get(2, 2);
      bool cond = CheckDA() || CheckDB() || CheckR(2) || CheckC(2);
      if (!me || me != cond) continue;
    }

    // C4
    {
      bool me = Get(3, 2);
      int cnt = 0;
      for (int i = 0; i < 5; i++) cnt += Get(i, 2);
      bool cond = (cnt <= 3);
      if (me != cond) continue;
    }

    // C5
    {
      bool me = Get(4, 2);
      bool cond = me;
      if (me != cond) continue;
    }

    // D1
    {
      bool me = Get(0, 3);
      bool cond = Get(3, 3);
      if (me != cond) continue;
    }

    // D2
    {
      bool me = Get(1, 3);
      bool cond = (bits.count() <= 17);
      if (me != cond) continue;
    }

    // D3
    {
      bool me = Get(2, 3);
      int cnt = 0;
      for (int i = 0; i < 5; i++) cnt += CheckC(i);
      bool cond = (cnt >= 2);
      if (me != cond) continue;
    }

    // D4
    {
      bool me = Get(3, 3);
      bool cond = Get(0, 3);
      if (me != cond) continue;
    }

    // D5
    {
      bool me = Get(4, 3);
      int cnt = (CheckDA() + CheckDB());
      for (int i = 0; i < 5; i++) cnt += (CheckR(i) + CheckC(i));
      bool cond = (cnt >= 3);
      if (me != cond) continue;
    }

    // E1
    {
      bool me = Get(0, 4);
      bool cond = CheckDB() || CheckR(0) || CheckC(4);
      if (me != cond) continue;
    }

    // E2
    {
      bool me = Get(1, 4);
      bool cond = (bingo.count() % 2 == 0);
      if (me != cond) continue;
    }

    // E3
    {
      bool me = Get(2, 4);
      bool cond = (25 - bingo.count() >= 10);
      if (me != cond) continue;
    }

    // E4
    {
      bool me = Get(3, 4);
      bool cond = CheckDA() || CheckDB();
      if (me != cond) continue;
    }

    // E5
    {
      bool me = Get(3, 4);
      bool cond = Get(4, 0);
      if (me != cond) continue;
    }

    vector<string> board(5, string(5, '.'));
    for (int i = 0; i < 25; i++) {
      if (bits[i]) board[i / 5][i % 5] = '#';
    }

    for (auto& s : board) cout << s << "\n";
    cout << "\n";
  }

  return 0;
}
