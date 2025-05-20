// Title : 징검다리의 징검다리
// Link  : https://www.acmicpc.net/problem/33934 
// Time  : 20 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, st, en, k;
  cin >> n >> st >> en;
  --st, --en;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  cin >> k;

  if (st > en) swap(st, en);

  int minn = en - st + 1, maxx = 0;
  for (int i = st; i >= 0; i--) {
    maxx += arr[i];
    if (arr[i] == 1) break;
  }
  for (int i = en; i < n; i++) {
    maxx += arr[i];
    if (arr[i] == 1) break;
  }
  for (int i = st + 1; i < en; i++) {
    maxx += arr[i];
  }
  cout << (minn <= k && k <= maxx);

  return 0;
}
