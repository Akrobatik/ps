// Title : 뱀
// Link  : https://www.acmicpc.net/problem/3190
// Time  : 0 ms
// Memory: 2120 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}};

int n;
bool apples[101][101];
bool snake[101][101];
vector<pair<int, int>> turns;
pair<int, int> memo[10101];
auto mb = memo, me = memo;
int cy = 1, cx = 1, dt = 0;

bool Move(int dy, int dx) {
  cy += dy, cx += dx;
  if (!(0 < cy && cy <= n && 0 < cx && cx <= n)) return false;
  if (snake[cy][cx]) return false;
  snake[cy][cx] = true;
  *me++ = {cy, cx};
  if (apples[cy][cx]) {
    apples[cy][cx] = false;
  } else {
    auto [ly, lx] = *mb++;
    snake[ly][lx] = false;
  }
  return true;
}

void Turn(int t) {
  if (turns.empty()) return;
  if (turns.back().first == t) {
    dt = (dt + turns.back().second) % 4;
    turns.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> n >> k;
  while (k--) {
    int y, x;
    cin >> y >> x;
    apples[y][x] = true;
  }

  int l;
  cin >> l;
  turns.resize(l);
  while (l--) {
    int t;
    char cmd;
    cin >> t >> cmd;
    turns[l] = {t, cmd == 'D' ? 1 : 3};
  }

  *me++ = {1, 1};
  snake[1][1] = true;
  for (int i = 1;; i++) {
    auto [dy, dx] = kDelta[dt];
    if (!Move(dy, dx)) {
      cout << i;
      break;
    }
    Turn(i);
  }

  return 0;
}
