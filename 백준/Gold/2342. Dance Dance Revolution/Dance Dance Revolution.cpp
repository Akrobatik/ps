#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 19;

int cost[5][5] = {
    {kMax, 2, 2, 2, 2},
    {kMax, 1, 3, 4, 3},
    {kMax, 3, 1, 3, 4},
    {kMax, 4, 3, 1, 3},
    {kMax, 3, 4, 3, 1}};

char seq[100001];
int memo[100000][5][5];

int Solve(int id, char l, char r) {
  char c = seq[id];
  if (l > r) swap(l, r);
  int& v = memo[id][l][r];
  if (c == 0) return 0;
  if (v != -1) return v;
  int lv = cost[l][c] + Solve(id + 1, c, r);
  int rv = cost[r][c] + Solve(id + 1, l, c);
  v = min<int>(lv, rv);
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
