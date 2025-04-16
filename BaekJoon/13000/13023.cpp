// Title : ABCDE
// Link  : https://www.acmicpc.net/problem/13023 
// Time  : 20 ms
// Memory: 2200 KB

#include <bits/stdc++.h>

using namespace std;

bool visited[2000];
vector<int> edges[2000];

void Traverse(int cur, int depth) {
  if (depth == 4) {
    cout << "1";
    exit(0);
  }

  visited[cur] = true;
  for (auto nxt : edges[cur]) {
    if (visited[nxt]) continue;
    Traverse(nxt, depth + 1);
  }
  visited[cur] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    Traverse(i, 0);
  }
  cout << "0";

  return 0;
}
