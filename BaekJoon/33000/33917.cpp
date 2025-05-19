// Title : 대결
// Link  : https://www.acmicpc.net/problem/33917 
// Time  : 152 ms
// Memory: 13744 KB

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

  vector<int> memo(n);
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
    memo[i] = (arr[i] == 1 ? brr[i] : -brr[i]);
    sum += memo[i];
  }
  int64_t ans = sum;

  int64_t rem = 0;
  int cnt = 0;
  for (int i = 0; i < n - 1; i ++) {
    sum -= memo[i];
    if (sum > 0) {
      rem += sum;
      ++cnt;
    }
  }

  cout << cnt + 1<< " " << ans + rem;

  return 0;
}