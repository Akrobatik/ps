#include <bits/stdc++.h>

using namespace std;

char seq[100001];
int memo[100000][5][5];

int GetCost(char a, char b) {
  if (a == b) return 1;
  if (a == 0) return 2;
  if (abs(a - b) != 2) return 3;
  return 4;
}

int Solve(int id, char l, char r) {
  char c = seq[id];
  int& v = memo[id][l][r];
  if (c == 0) return 0;
  if (v != -1) return v;
  if (l == r && l != 0) return 1 << 19;

  int lv = GetCost(l, c) + Solve(id + 1, c, r);
  int rv = GetCost(r, c) + Solve(id + 1, l, c);
  v = lv < rv ? lv : rv;
  return v;
}

int main() {
  memset(memo, -1, sizeof(memo));
  char* ptr = seq;
  do cin >> *ptr;
  while (*ptr++ -= '0');
  cout << Solve(0, 0, 0);

  return 0;
}
