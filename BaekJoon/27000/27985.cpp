// Title : 멘토링 매칭
// Link  : https://www.acmicpc.net/problem/27985 
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

int memo[21][21];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> memo[i][j];
    }
  }

  vector<int> idxs(n + 1, 1), arr(n + 1), brr(n + 1);

  queue<int> q;
  for (int i = 1; i <= n; i++) q.push(i);

  while (!q.empty()) {
    int a = q.front();
    q.pop();

    if (idxs[a] > n) continue;

    int b = memo[a][idxs[a]++];
    if (brr[b] == 0) {
      arr[a] = b;
      brr[b] = a;
    } else {
      int cur = abs(b - a), old = abs(b - brr[b]);
      if (cur > old || (cur == old && a < brr[b])) {
        arr[brr[b]] = 0;
        q.push(brr[b]);
        arr[a] = b;
        brr[b] = a;
      } else {
        q.push(a);
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << arr[i] << " ";

  return 0;
}
