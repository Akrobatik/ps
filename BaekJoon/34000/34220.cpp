// Title : 그래프 리뷰 유튜버
// Link  : https://www.acmicpc.net/problem/34220 
// Time  : 36 ms
// Memory: 8428 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

vector<int> edges[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (edges[i].size() < 3) continue;

    int a = edges[i][0], b = edges[i][1], c = edges[i][2];
    cout << "3\n"
         << a << " " << b << "\n"
         << b << " " << c << "\n"
         << c << " " << a << "\n";
    return 0;
  }

  int st;
  for (int i = 1; i <= n; i++) {
    if (edges[i].size() != 1) continue;
    st = i;
    break;
  }

  int arr[4];
  [&](this auto&& self, int cur, int par, int idx) {
    arr[idx] = cur;
    if (idx + 1 == 4) return;

    for (auto nxt : edges[cur]) {
      if (nxt == par || (idx < 2 && edges[nxt].size() == 1)) continue;
      self(nxt, cur, idx + 1);
      break;
    }
  }(st, 0, 0);

  cout << "3\n"
       << arr[0] << " " << arr[2] << "\n"
       << arr[0] << " " << arr[3] << "\n"
       << arr[1] << " " << arr[3] << "\n";

  return 0;
}