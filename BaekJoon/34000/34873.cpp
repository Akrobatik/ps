// Title : 사탕 나눠주기
// Link  : https://www.acmicpc.net/problem/34873 
// Time  : 36 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int m = n << 1;

  vector<int> arr(m);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  bool ok = true;
  int idx = 0;
  while (idx < m) {
    int val = arr[idx], nxt = idx;
    while (nxt < m && val == arr[nxt]) ++nxt;
    ok &= (nxt - idx <= 2), idx = nxt;
  }
  cout << (ok ? "Yes" : "No");

  return 0;
}