// Title : 전쟁 - 땅따먹기
// Link  : https://www.acmicpc.net/problem/1270 
// Time  : 3364 ms
// Memory: 2808 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int64_t> arr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    arr.resize(n);
    for (auto& e : arr) cin >> e;
    sort(arr.begin(), arr.end());

    int64_t ans = INT64_MAX;
    int idx = 0, half = n >> 1;
    while (idx < n) {
      int nxt = idx, cnt = 0;
      while (nxt < n && arr[idx] == arr[nxt]) ++nxt, ++cnt;
      if (cnt > half) {
        ans = arr[idx];
        break;
      }
      idx = nxt;
    }

    if (ans != INT64_MAX) {
      cout << ans << "\n";
    } else {
      cout << "SYJKGW\n";
    }
  }

  return 0;
}
