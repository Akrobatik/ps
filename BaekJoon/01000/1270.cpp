// Title : 전쟁 - 땅따먹기
// Link  : https://www.acmicpc.net/problem/1270 
// Time  : 3180 ms
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

    bool ok = false;
    int half = n >> 1, limit = n - half;
    for (int i = 0; i < limit; i++) {
      if (arr[i] == arr[i + half]) {
        cout << arr[i] << "\n";
        ok = true;
        break;
      }
    }

    if (!ok) cout << "SYJKGW\n";
  }

  return 0;
}
