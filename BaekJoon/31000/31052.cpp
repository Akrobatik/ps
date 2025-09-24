// Title : Relocation
// Link  : https://www.acmicpc.net/problem/31052 
// Time  : 28 ms
// Memory: 2360 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  while (q--) {
    int cmd, a, b;
    cin >> cmd >> a >> b;
    if (cmd == 1) {
      arr[a] = b;
    } else {
      cout << abs(arr[a] - arr[b]) << "\n";
    }
  }

  return 0;
}
