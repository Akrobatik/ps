// Title : 공연 준비
// Link  : https://www.acmicpc.net/problem/34344 
// Time  : 92 ms
// Memory: 4144 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  pos[0] = kInf;

  vector<int> cnt(n + 1);
  vector<vector<int>> memo(n + 1, vector<int>(n + 1, kInf)), mnxt;
  memo[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    mnxt.assign(n + 1, vector<int>(n + 1, kInf));

    int pi = pos[i];
    for (int j = pi; j <= n; j++) ++cnt[j];

    for (int j = 0; j < i; j++) {
      for (int k = 0; k <= n; k++) {
        if (memo[j][k] == kInf) continue;

        int cur = memo[j][k] + (pi <= k ? cnt[k] - cnt[pi] : 0);
        mnxt[j][k] = min<int>(mnxt[j][k], cur);
        if (k < pi) mnxt[j + 1][pi] = min<int>(mnxt[j + 1][pi], cur);
        if (k > pi) mnxt[j + 1][k] = min<int>(mnxt[j + 1][k], cur);
      }
    }
    swap(memo, mnxt);
  }

  for (int i = 1; i <= n; i++) {
    int minn = kInf;
    for (int j = i; j <= n; j++) minn = min<int>(minn, memo[i][j]);
    cout << minn << " ";
  }

  return 0;
}
