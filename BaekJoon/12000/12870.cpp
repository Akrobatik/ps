// Title : 뮤탈리스크 2
// Link  : https://www.acmicpc.net/problem/12870 
// Time  : 48 ms
// Memory: 7016 KB

#include <bits/stdc++.h>

using namespace std;

constexpr tuple<int, int, int> kDelta[] = {
    {1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1}};

bool visited[61][61][61];

vector<tuple<int, int, int>> cands[20];
int memo[21][141][401];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n <= 3) {
    int arr[3] = {};
    for (int i = 0; i < n; i++) cin >> arr[i];

    queue<tuple<int, int, int>> q;

    auto Push = [&](int a, int b, int c, int da, int db, int dc) {
      if ((a -= da) < 0) a = 0;
      if ((b -= db) < 0) b = 0;
      if ((c -= dc) < 0) c = 0;
      if (visited[a][b][c]) return;
      visited[a][b][c] = true;
      q.push({a, b, c});
    };

    Push(arr[0], arr[1], arr[2], 0, 0, 0);
    for (int i = 0;; i++) {
      int nq = q.size();
      while (nq--) {
        auto [a, b, c] = q.front();
        q.pop();

        if (a == 0 && b == 0 && c == 0) {
          cout << i;
          return 0;
        }

        for (auto [da, db, dc] : kDelta) {
          Push(a, b, c, da, db, dc);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j <= 7; j++) {
      for (int k = 0; k <= 20; k++) {
        int l = x - j * 9 - k * 3;
        cands[i].push_back({j, k, max<int>(l, 0)});
      }
    }
  }

  memset(memo, 0x7f, sizeof(memo));
  memo[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (auto [a, b, c] : cands[i]) {
      for (int j = 0; j <= i * 7; j++) {
        for (int k = 0; k <= i * 20; k++) {
          memo[i + 1][j + a][k + b] = min<int>(memo[i + 1][j + a][k + b], memo[i][j][k] + c);
        }
      }
    }
  }

  int minn = INT_MAX, maxx = 0;
  for (int i = 0; i <= n * 7; i++) {
    for (int j = 0; j <= n * 20; j++) {
      int k = memo[n][i][j];
      minn = min<int>(minn, max<int>({i, j, k}));
    }
  }
  cout << minn;

  return 0;
}
