// Title : 나무 자르기
// Link  : https://www.acmicpc.net/problem/14247 
// Time  : 12 ms
// Memory: 2268 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t ans = 0;
  int n;
  cin >> n;
  vector<int> arr(n);
  while (n--) {
    int x;
    cin >> x;
    ans += x;
  }

  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  for (int i = 0; i < arr.size(); i++) {
    ans += (int64_t)arr[i] * i;
  }
  cout << ans;

  return 0;
}
