// Title : N+1 행사
// Link  : https://www.acmicpc.net/problem/32758 
// Time  : 28 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  for (int i = 0; i < n; i++) {
    int64_t x;
    cin >> x;
    cout << (x ? x - (x - 1) / arr[i] : 0) << " ";
  }

  return 0;
}