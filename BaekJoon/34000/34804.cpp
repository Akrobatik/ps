// Title : 배점 배정하기
// Link  : https://www.acmicpc.net/problem/34804 
// Time  : 340 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    int val = 0;
    int x;
    cin >> x;
    while (x--) {
      int y;
      cin >> y, --y;
      val |= (1 << y);
    }
    arr[i] = val;
  }

  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  if (arr.size() != n) {
    cout << "-1";
    return 0;
  }

  for (int i = 0; i < m; i++) {
    cout << (1 << i) << " ";
  }

  return 0;
}