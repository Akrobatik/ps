// Title : 폴짝폴짝
// Link  : https://www.acmicpc.net/problem/1326 
// Time  : 0 ms
// Memory: 2184 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int a, b;
  cin >> a >> b;
  --a, --b;
  vector<int> memo(n, -1);

  queue<int> q;

  auto Push = [&](int x, int w) {
    if (memo[x] != -1) return;
    memo[x] = w;
    q.push(x);
  };

  Push(a, 0);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    int x = arr[cur], w = memo[cur] + 1;
    for (int i = cur + x; i < n; i += x) Push(i, w);
    for (int i = cur - x; i >= 0; i -= x) Push(i, w);
  }
  cout << memo[b];

  return 0;
}
