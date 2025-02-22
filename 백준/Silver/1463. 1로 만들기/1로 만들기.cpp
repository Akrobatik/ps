#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  queue<int> q;
  memo[1] = true;
  q.push(1);
  int i;
  for (i = 0; !memo[n]; i++) {
    int nq = q.size();
    while (nq--) {
      int v = q.front();
      q.pop();
      int arr[] = {v + 1, v << 1, (v << 1) + v};
      for (int e : arr) {
        if (e > n || memo[e]) continue;
        memo[e] = true;
        q.push(e);
      }
    }
  }
  cout << i;

  return 0;
}
