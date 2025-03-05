#include <bits/stdc++.h>

using namespace std;

bool visited[21][21][21];
int memo[21][21][21];

int W(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return W(20, 20, 20);

  if (visited[a][b][c]) return memo[a][b][c];
  visited[a][b][c] = true;
  auto& ret = memo[a][b][c];

  if (a < b && b < c) return ret = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
  return ret = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  while (cin >> a >> b >> c && (a != -1 || b != -1 || c != -1)) {
    cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << "\n";
  }

  return 0;
}
