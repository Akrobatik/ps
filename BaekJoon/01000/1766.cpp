// Title : 문제집
// Link  : https://www.acmicpc.net/problem/1766
// Time  : 24 ms
// Memory: 3964 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> conds[32001];
int memo[32001];

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

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; i++) {
    if (memo[i] == 0) pq.push(i);
  }

  while (!pq.empty()) {
    int id = pq.top();
    pq.pop();

    cout << id << " ";

    for (int cid : conds[id]) {
      if (--memo[cid] == 0) pq.push(cid);
    }
  }

  return 0;
}
