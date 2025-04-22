// Title : 최종 순위
// Link  : https://www.acmicpc.net/problem/3665 
// Time  : 8 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr, brr, ans;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    arr.assign(n + 1, 0);
    brr.assign(n + 1, 0);
    ans.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      arr[x] = brr[x] = i;
    }

    int m;
    cin >> m;
    while (m--) {
      int a, b;
      cin >> a >> b;
      if (arr[a] > arr[b]) swap(a, b);
      ++brr[a], --brr[b];
    }

    bool ok = true;
    for (int i = 1; ok && i <= n; i++) {
      int x = brr[i];
      ok = (ans[x] == 0);
      ans[x] = i;
    }

    if (ok) {
      for (int i = 1; i <= n; i++) cout << ans[i] << " ";
      cout << "\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }

  return 0;
}
