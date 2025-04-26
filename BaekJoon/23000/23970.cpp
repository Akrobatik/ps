// Title : 알고리즘 수업 - 버블 정렬 3
// Link  : https://www.acmicpc.net/problem/23970 
// Time  : 284 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  int cnt = 0;
  vector<bool> crr(n);
  for (int i = 0; i < n; i++) {
    if (arr[i] != brr[i]) continue;
    crr[i] = true;
    ++cnt;
  }

  if (cnt == n) {
    cout << "1";
    return 0;
  }

  int idx = n;
  while (--idx) {
    for (int i = 0; i < idx; i++) {
      if (arr[i] < arr[i + 1]) continue;
      cnt -= (crr[i] + crr[i + 1]);
      swap(arr[i], arr[i + 1]);
      crr[i] = (arr[i] == brr[i]);
      crr[i + 1] = (arr[i + 1] == brr[i + 1]);
      cnt += (crr[i] + crr[i + 1]);
      if (cnt == n) {
        cout << "1";
        return 0;
      }
    }
  }
  cout << "0";

  return 0;
}
