// Title : 초차원전쟁 이나
// Link  : https://www.acmicpc.net/problem/11579 
// Time  : 692 ms
// Memory: 3128 KB

#include <bits/stdc++.h>

using namespace std;

int memo[500][500];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int64_t> arr;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> memo[i][j];
      }
    }

    arr.resize(n);
    for (auto& e : arr) cin >> e;

    int64_t sum = 0;
    int idx = 0;
    while (idx < n && arr[idx] >= 0) {
      int64_t x = arr[idx];
      sum += x;
      for (int i = idx; i < n; i++) arr[i] -= x * memo[idx][i];
      ++idx;
    }

    if (idx == n && sum <= (int)2e10) {
      cout << "1 " << sum << "\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}
