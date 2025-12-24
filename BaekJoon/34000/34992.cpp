// Title : 트리 선물하기
// Link  : https://www.acmicpc.net/problem/34992 
// Time  : 64 ms
// Memory: 5784 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int lv = arr[0], rv = arr[n - 1];
  if (lv != 0) {
    cout << "-1";
    return 0;
  }

  vector<int> axr;

  int val = 1;
  for (int i = 1; i < n; i++) {
    int dt = (arr[i] - arr[i - 1]);
    int nxt = val + dt;
    for (int j = nxt - 2; j >= val; j -= 2) {
      axr.push_back(j);
    }
    val = nxt;
  }

  int na = axr.size();
  vector<pair<int, int>> lr(na);
  for (int i = 0; i < na; i++) {
    int x = axr[i];
    lr[x >> 1] = {i * 2, (i + 1 < na ? axr[i + 1] : na * 2)};
  }

  cout << na << "\n";
  for (auto [l, r] : lr) cout << l << " " << r << "\n";

  return 0;
}