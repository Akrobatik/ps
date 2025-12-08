// Title : 나는 건포도가 싫어요
// Link  : https://www.acmicpc.net/problem/32986 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t arr[3];
  for (auto& e : arr) cin >> e;
  sort(arr, arr + 3);

  int64_t ans = (arr[0] - 1) >> 1;
  if (arr[0] == 3 && arr[1] == 3) ans = min<int64_t>(ans, (arr[2] - 2) >> 1);
  cout << ans;

  return 0;
}