// Title : Motorway Stops
// Link  : https://www.acmicpc.net/problem/35251 
// Time  : 8 ms
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

  int maxx = 0;
  for (int i = 1; i < n; i++) {
    maxx = max<int>(maxx, arr[i] - arr[i - 1]);
  }

  int minn = INT_MAX;
  for (int i = 1; i + 1 < n; i++) {
    int val = max<int>(maxx, arr[i + 1] - arr[i - 1]);
    minn = min<int>(minn, val);
  }
  cout << minn;

  return 0;
}