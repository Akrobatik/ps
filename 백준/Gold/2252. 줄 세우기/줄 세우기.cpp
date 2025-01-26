#include <bits/stdc++.h>

using namespace std;

int seq[32000];
int memo[32001];
bool visited[32001];
vector<int> conds[32001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    ++memo[b];
    conds[a].push_back(b);
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (memo[i] == 0) q.push(i);
  }

  int* ptr = seq;
  while (!q.empty()) {
    int id = q.front();
    q.pop();

    if (visited[id]) continue;
    visited[id] = true;
    *ptr++ = id;

    for (int cid : conds[id]) {
      if (--memo[cid] == 0) {
        q.push(cid);
      }
    }
  }

  ptr = seq;
  while (n--) cout << *ptr++ << " ";
  cout << "\n";

  return 0;
}
