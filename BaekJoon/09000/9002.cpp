// Title : Match Maker
// Link  : https://www.acmicpc.net/problem/9002 
// Time  : 8 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> idxs, arr, brr;
  vector<vector<int>> axr, bxr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    idxs.assign(n + 1, 1);
    arr.assign(n + 1, 0);
    brr.assign(n + 1, 0);
    axr.assign(n + 1, vector<int>(n + 1));
    bxr.assign(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> axr[i][j];
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int k;
        cin >> k;
        bxr[i][k] = j;
      }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    while (!q.empty()) {
      int a = q.front();
      q.pop();

      if (idxs[a] >= n) continue;

      int b = axr[a][idxs[a]++];
      if (brr[b] == 0) {
        arr[a] = b;
        brr[b] = a;
      } else {
        int cur = bxr[b][a], old = bxr[b][brr[b]];
        if (cur < old) {
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
    cout << "\n";
  }

  return 0;
}
