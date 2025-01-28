#include <bits/stdc++.h>

using namespace std;

int mem[101];
int cost[101];
int memo[101][10001];
// [app][cost-sum] = w min

// Aij = Ai-1j
//     = Ai-1j-cost + mem
// Ai-1j, Ai-1j-cost 가 있는지 체크

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> mem[i];
  for (int i = 1; i <= n; i++) cin >> cost[i];

  int maxx = 0;
  for (int i = 1; i <= n; i++) {
    int mm = mem[i];
    int c = cost[i];
    int maxx_old = maxx;
    maxx += c;
    for (int j = maxx_old + 1; j <= maxx; j++) memo[i - 1][j] = -1;

    int j = 0;
    for (; j < c; j++) memo[i][j] = memo[i - 1][j];
    for (; j <= maxx; j++) {
      if (memo[i - 1][j] != -1 && memo[i - 1][j - c] != -1) {
        memo[i][j] = max<int>(memo[i - 1][j], memo[i - 1][j - c] + mm);
      } else if (memo[i - 1][j] != -1) {
        memo[i][j] = memo[i - 1][j];
      } else if (memo[i - 1][j - c] != -1) {
        memo[i][j] = memo[i - 1][j - c] + mm;
      } else {
        memo[i][j] = -1;
      }
    }
  }

  for (int i = 0; i <= maxx; i++) {
    if (memo[n][i] < m) continue;
    cout << i << endl;
    break;
  }

  return 0;
}
