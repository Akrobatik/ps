// Title : 스트릭 채우기
// Link  : https://www.acmicpc.net/problem/34034 
// Time  : 44 ms
// Memory: 4372 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = {x, i + 1};
  }
  sort(arr.begin(), arr.end());

  int cur = 0, cnt = 0;
  vector<int> ans(k);
  for (auto [x, i] : arr) {
    cur += x;
    if (cur > k) break;
    ++cnt;
    ans[cur - 1] = i;
  }

  if (cnt + m < k) {
    cout << "-1";
  } else {
    for (auto e : ans) cout << e << " ";
  }

  return 0;
}
