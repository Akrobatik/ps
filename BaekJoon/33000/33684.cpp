// Title : 소스 더하기
// Link  : https://www.acmicpc.net/problem/33684 
// Time  : 20 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  if (arr.back() > k) {
    cout << "0";
    return 0;
  }
  if (arr.front() <= 0) {
    cout << "-1";
    return 0;
  }

  int64_t sum = 0;
  for (int i = 1; i < n; i++) {
    sum += (k - arr[i]) / arr[0];
  }
  cout << sum + 1;

  return 0;
}
