#include <bits/stdc++.h>

using namespace std;

int rows, cols;
char digits[20][21];
char visited[26];
int ans;

void Traverse(int depth, int row, int col) {
  ans = max<int>(ans, depth + 1);
  if (ans == 26) return;
  visited[depth] = digits[row][col];

  auto b = begin(visited);
  auto e = b + depth + 1;
  if (row > 0 && find(b, e, digits[row - 1][col]) == e)
    Traverse(depth + 1, row - 1, col);
  if (row < rows - 1 && find(b, e, digits[row + 1][col]) == e)
    Traverse(depth + 1, row + 1, col);
  if (col > 0 && find(b, e, digits[row][col - 1]) == e)
    Traverse(depth + 1, row, col - 1);
  if (col < cols - 1 && find(b, e, digits[row][col + 1]) == e)
    Traverse(depth + 1, row, col + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> rows >> cols;
  for (int i = 0; i < rows; i++) {
    cin >> digits[i];
  }

  Traverse(0, 0, 0);
  cout << ans << endl;

  return 0;
}
