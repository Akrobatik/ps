#include <bits/stdc++.h>

using namespace std;

int memo[10001];
vector<pair<int, int>> edges[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d;
  cin >> n >> d;
  while (n--) {
    int s, e, l;
    cin >> s >> e >> l;
    edges[e].push_back({s, l});
  }

  for (int i = 1; i <= d; i++) {
    memo[i] = memo[i - 1] + 1;
    for (auto [b, l] : edges[i]) {
      memo[i] = min<int>(memo[i], memo[b] + l);
    }
  }
  cout << memo[d];

  return 0;
}
