// Title : 3교시： 수학
// Link  : https://www.acmicpc.net/problem/33633
// Time  : 36 ms
// Memory: 6936 KB

#include <bits/stdc++.h>

using namespace std;

void Test();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  queue<int64_t> q;
  q.push(1);
  for (int i = 1; i < n; i++) {
    int nq = q.size();
    while (nq--) {
      auto x = q.front();
      q.pop();

      q.push(x << 1);
      if ((x - 1) % 3 == 0 && x / 3 > 1 && (x / 3) % 2 == 1) {
        q.push(x / 3);
      }
    }
  }

  vector<int64_t> ans;
  while (!q.empty()) {
    ans.push_back(q.front());
    q.pop();
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << "\n";

  return 0;
}
