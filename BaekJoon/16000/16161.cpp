// Title : 가장 긴 증가하는 팰린드롬 부분수열
// Link  : https://www.acmicpc.net/problem/16161 
// Time  : 12 ms
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
  for (int i = 0; i < n; i++) {
    int l = i, r = i;
    while (l - 1 >= 0 && r + 1 < n && arr[l - 1] < arr[l] && arr[l - 1] == arr[r + 1]) --l, ++r;
    maxx = max<int>(maxx, r - l + 1);
  }
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] != arr[i]) continue;
    int l = i - 1, r = i;
    while (l - 1 >= 0 && r + 1 < n && arr[l - 1] < arr[l] && arr[l - 1] == arr[r + 1]) --l, ++r;
    maxx = max<int>(maxx, r - l + 1);
  }
  cout << maxx;

  return 0;
}
