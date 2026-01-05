// Title : 기상청 인턴 신현수
// Link  : https://www.acmicpc.net/problem/2435 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int maxx = INT_MIN;
  for (int i = 0; i + k <= n; i++) {
    int cur = 0;
    for (int j = 0; j < k; j++) {
      cur += arr[i + j];
    }
    maxx = max<int>(maxx, cur);
  }
  cout << maxx;

  return 0;
}