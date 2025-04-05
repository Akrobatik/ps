// Title : 외판원 순회
// Link  : https://www.acmicpc.net/problem/2098
// Time  : 28 ms
// Memory: 6116 KB

#include <bits/stdc++.h>

using namespace std;

int n;
int mat[16][16];
int memo[16][1 << 16];

int Traverse(int pos, int bits) {
  bits |= 1 << pos;
  if (bits + 1 == 1 << n) {
    if (mat[pos][0] == 0) return INT_MAX;
    return mat[pos][0];
  }

  int& ref = memo[pos][bits];
  if (ref) return ref;
  ref = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (i == pos || (bits & (1 << i)) || mat[pos][i] == 0) continue;
    int cost = Traverse(i, bits);
    if (cost != INT_MAX) ref = min<int>(ref, cost + mat[pos][i]);
  }
  return ref;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> mat[i][j];
  }

  cout << Traverse(0, 0);

  return 0;
}
