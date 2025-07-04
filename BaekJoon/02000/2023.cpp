// Title : 신기한 소수
// Link  : https://www.acmicpc.net/problem/2023 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int x) {
  if (x <= 1) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  queue<int> q;
  q.push(0);

  for (int i = 0; i < n; i++) {
    int nq = q.size();
    while (nq--) {
      auto x = q.front();
      q.pop();

      x *= 10;
      for (int j = 1; j <= 9; j++) {
        int y = x + j;
        if (IsPrime(y)) q.push(y);
      }
    }
  }

  vector<int> ans;
  while (!q.empty()) ans.push_back(q.front()), q.pop();
  sort(ans.begin(), ans.end());
  for (auto e : ans) cout << e << "\n";

  return 0;
}
