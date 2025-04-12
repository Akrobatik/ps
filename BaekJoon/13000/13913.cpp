// Title : 숨바꼭질 4
// Link  : https://www.acmicpc.net/problem/13913 
// Time  : 8 ms
// Memory: 3896 KB

#include <bits/stdc++.h>

using namespace std;

int path[200001];
bool memo[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  queue<int> q;
  path[n] = n;
  memo[n] = true;
  q.push(n);
  int i;
  for (i = 0; !memo[k]; i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      int arr[] = {cur - 1, cur + 1, cur * 2};
      for (auto e : arr) {
        if (0 <= e && e <= 200000 && !memo[e]) {
          path[e] = cur;
          memo[e] = true;
          q.push(e);
        }
      }
    }
  }
  vector<int> ans;
  int p = k;
  for (;;) {
    ans.push_back(p);
    if (p == path[p]) break;
    p = path[p];
  }

  cout << i << "\n";
  for (auto e : views::reverse(ans)) cout << e << " ";

  return 0;
}
