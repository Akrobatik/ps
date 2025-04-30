// Title : 자리 신청
// Link  : https://www.acmicpc.net/problem/32943 
// Time  : 44 ms
// Memory: 3980 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, c, k;
  cin >> x >> c >> k;
  vector<tuple<int, int, int>> logs(k);
  for (auto& [t, s, n] : logs) cin >> t >> s >> n;
  sort(logs.begin(), logs.end());

  vector<int> arr(c + 1), brr(x + 1);
  for (auto [t, s, n] : logs) {
    if (arr[s]) continue;
    if (brr[n]) arr[brr[n]] = 0;
    arr[s] = n, brr[n] = s;
  }

  for (int i = 1; i <= x; i++) {
    if (brr[i]) cout << i << " " << brr[i] << "\n";
  }

  return 0;
}
