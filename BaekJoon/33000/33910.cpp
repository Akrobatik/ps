// Title : 합의 최소
// Link  : https://www.acmicpc.net/problem/33910 
// Time  : 48 ms
// Memory: 3976 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int64_t sum = 0;
  int cur = INT32_MAX;
  while (n--) {
    cur = min<int>(cur, arr[n]);
    sum += cur;
  }
  cout << sum;

  return 0;
}