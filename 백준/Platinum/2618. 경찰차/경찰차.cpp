#include <bits/stdc++.h>

using namespace std;

int n, w;
int memo[1001][1001];
pair<int, int> cases[1001];

pair<int, int> GetCoord(int i, bool is_b) {
  if (i) return cases[i];
  int x = is_b ? n : 1;
  return {x, x};
}

int Traverse(int a, int b) {
  int nxt = max<int>(a, b) + 1;
  if (nxt == w + 1) return 0;

  auto& ret = memo[a][b];
  if (ret) return ret;

  auto [ay, ax] = GetCoord(a, false);
  auto [by, bx] = GetCoord(b, true);
  auto [ny, nx] = GetCoord(nxt, false);
  int ad = abs(ay - ny) + abs(ax - nx);
  int bd = abs(by - ny) + abs(bx - nx);
  return ret = min<int>(Traverse(nxt, b) + ad, Traverse(a, nxt) + bd);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> w;
  for (int i = 1; i <= w; i++) {
    cin >> cases[i].first >> cases[i].second;
  }

  int minn = Traverse(0, 0);
  cout << minn << "\n";
  for (int i = 1, a = 0, b = 0; i <= w; i++) {
    auto [ay, ax] = GetCoord(a, false);
    auto [by, bx] = GetCoord(b, true);
    auto [ny, nx] = GetCoord(i, false);
    int ad = abs(ay - ny) + abs(ax - nx);
    int bd = abs(by - ny) + abs(bx - nx);
    if (minn == memo[i][b] + ad) {
      a = i, minn -= ad;
      cout << "1\n";
    } else {
      b = i, minn -= bd;
      cout << "2\n";
    }
  }

  return 0;
}
