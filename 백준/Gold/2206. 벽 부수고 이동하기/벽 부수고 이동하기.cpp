#include <bits/stdc++.h>

using namespace std;

int8_t mat[1000][1000];
bool visited[1000][1000][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int rows, cols;
  cin >> rows >> cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> mat[i][j];
      mat[i][j] &= 1;
    }
  }

  queue<tuple<int16_t, int16_t, int32_t, int8_t>> q;
  q.push(make_tuple(0, 0, 1, 0));
  visited[0][0][0] = visited[0][0][1] = true;
  int32_t ans = -1;
  while (!q.empty()) {
    auto [y, x, cost, collided] = q.front();
    q.pop();

    if (y + 1 == rows && x + 1 == cols) {
      ans = cost;
      break;
    }

    for (int i = 0; i < 4; i++) {
      static constexpr int8_t dy[] = {0, 0, 1, -1};
      static constexpr int8_t dx[] = {1, -1, 0, 0};

      int16_t yy = y + dy[i];
      int16_t xx = x + dx[i];
      if (0 <= yy && yy < rows && 0 <= xx && xx < cols) {
        if (mat[yy][xx] == 0) {
          if (!collided && !visited[yy][xx][0]) {
            visited[yy][xx][0] = true;
            q.push(make_tuple(yy, xx, cost + 1, 0));
          } else if (collided && !visited[yy][xx][1]) {
            visited[yy][xx][1] = true;
            q.push(make_tuple(yy, xx, cost + 1, 1));
          }
        } else if (!collided && !visited[yy][xx][1]) {
          visited[yy][xx][1] = true;
          q.push(make_tuple(yy, xx, cost + 1, 1));
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
