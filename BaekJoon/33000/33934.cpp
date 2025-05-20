// Title : 징검다리의 징검다리
// Link  : https://www.acmicpc.net/problem/33934 
// Time  : 16 ms
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

  while (st && arr[st] != 1) --st;
  while (en + 1 < n && arr[en] != 1) ++en;
  for (int i = st; i <= en; i++) maxx += arr[i];

  cout << (minn <= k && k <= maxx);

  return 0;
}
