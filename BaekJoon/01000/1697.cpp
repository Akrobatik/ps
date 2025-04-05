// Title : 숨바꼭질
// Link  : https://www.acmicpc.net/problem/1697
// Time  : 0 ms
// Memory: 2480 KB

#include <bits/stdc++.h>

using namespace std;

bool memo[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  queue<int> q;
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
          memo[e] = true;
          q.push(e);
        }
      }
    }
  }
  cout << i;

  return 0;
}
