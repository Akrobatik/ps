// Title : 버블 소트
// Link  : https://www.acmicpc.net/problem/1377 
// Time  : 100 ms
// Memory: 6916 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), brr(n);
  for (auto& e : arr) cin >> e;
  iota(brr.begin(), brr.end(), 0);
  stable_sort(brr.begin(), brr.end(), [&](int lhs, int rhs) {
    return arr[lhs] < arr[rhs];
  });

  int maxx = 0;
  for (int i = 0; i < n; i++) {
    maxx = max<int>(maxx, brr[i] - i);
  }
  cout << maxx + 1;

  return 0;
}
