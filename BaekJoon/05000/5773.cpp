// Title : The Splitting Club
// Link  : https://www.acmicpc.net/problem/5773 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;

  int n;
  long double r;
  while (cin >> n >> r && n) {
    int tmp;
    arr.resize(n);
    for (auto& e : arr) cin >> e >> tmp;
    sort(arr.begin(), arr.end());

    int idx = 0, cnt = 0;
    while (idx < n) {
      ++cnt;
      int nxt = idx, ub = (int)(r * arr[idx]);
      while (nxt < n && arr[nxt] <= ub) ++nxt;
      idx = nxt;
    }
    cout << cnt << "\n";
  }

  return 0;
}