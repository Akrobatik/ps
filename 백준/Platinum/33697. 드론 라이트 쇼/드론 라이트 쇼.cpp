#include <bits/stdc++.h>

using namespace std;

bool uv[100001], dv[100001];
vector<int> ue[100001], de[100001];
int memo[100001];

void Up(int cur, int color) {
  uv[cur] = true;
  if (memo[cur] == 0) memo[cur] = color;

  for (auto nxt : ue[cur]) {
    if (uv[nxt]) continue;
    Up(nxt, color);
  }
}

void Down(int cur, int color) {
  dv[cur] = true;
  if (memo[cur] == 0) memo[cur] = color;

  for (auto nxt : de[cur]) {
    if (dv[nxt]) continue;
    Down(nxt, color);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    ue[a].push_back(b);
    de[b].push_back(a);
  }

  vector<tuple<int, int, int>> queries(q);
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    queries[q] = {a, b, c};
  }

  for (auto [a, b, c] : queries) {
    if (b == 1) {
      if (!uv[a]) Up(a, c);
    } else {
      if (!dv[a]) Down(a, c);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << memo[i] << " ";
  }

  return 0;
}
