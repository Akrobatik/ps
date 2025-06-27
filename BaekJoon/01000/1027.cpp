// Title : 고층 건물
// Link  : https://www.acmicpc.net/problem/1027 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int maxx = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    int64_t d = 1, h = -1e9;
    for (int l = i - 1; l >= 0; l--) {
      if (d * (arr[l] - arr[i]) <= h * (i - l)) continue;
      ++cnt;
      d = i - l, h = arr[l] - arr[i];
    }
    d = 1, h = -1e9;
    for (int r = i + 1; r < n; r++) {
      if (d * (arr[r] - arr[i]) <= h * (r - i)) continue;
      ++cnt;
      d = r - i, h = arr[r] - arr[i];
    }
    maxx = max<int>(maxx, cnt);
  }
  cout << maxx;

  return 0;
}
