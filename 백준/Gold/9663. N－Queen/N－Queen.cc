#include <bits/stdc++.h>

using namespace std;

int units[15];
int n;

bool Check(int col, int row) {
  for (int i = 0; i < col; i++) {
    int delta = col - i;
    if (units[i] == row ||
        units[i] - delta == row ||
        units[i] + delta == row) {
      return false;
    }
  }
  return true;
}

int NQueenUnit(int col, int row) {
  int result = 0;
  units[col] = row;
  if (Check(col, row)) {
    if (col + 1 == n) return 1;
    for (int i = 0; i < n; i++) {
      result += NQueenUnit(col + 1, i);
    }
  }
  return result;
}

int NQueen() {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result += NQueenUnit(0, i);
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  cout << NQueen() << endl;

  return 0;
}
