// Title : 수열의 변화
// Link  : https://www.acmicpc.net/problem/1551
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
  for (int i = 0; i < n; i++) {
    char _;
    cin >> arr[i] >> _;
  }

  while (k--) {
    for (int i = 1; i < arr.size(); i++) {
      arr[i - 1] = arr[i] - arr[i - 1];
    }
    arr.pop_back();
  }

  cout << arr[0];
  for (int i = 1; i < arr.size(); i++) {
    cout << "," << arr[i];
  }

  return 0;
}
