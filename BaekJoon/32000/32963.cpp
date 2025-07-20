// Title : 맛있는 사과
// Link  : https://www.acmicpc.net/problem/32963 
// Time  : 140 ms
// Memory: 4372 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> arr(n);
  for (auto& [t, s] : arr) cin >> t;
  for (auto& [t, s] : arr) cin >> s;
  sort(arr.begin(), arr.end());

  int maxx = 0, cnt = 0;
  vector<int> memo(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    int s = arr[i].second;
    if (s > maxx) {
      maxx = s, cnt = 1;
    } else if (s == maxx) {
      ++cnt;
    }
    memo[i] = cnt;
  }

  while (q--) {
    int x;
    cin >> x;
    auto it = lower_bound(arr.begin(), arr.end(), x, [](const pair<int, int>& lhs, int rhs) {
      return lhs.first < rhs;
    });
    cout << memo[it - arr.begin()] << "\n";
  }

  return 0;
}
