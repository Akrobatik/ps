// Title : 대표값2
// Link  : https://www.acmicpc.net/problem/2587 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[5];
  for (auto& e : arr) cin >> e;
  sort(arr, arr + 5);
  cout << accumulate(arr, arr + 5, 0) / 5 << "\n"
       << arr[2];

  return 0;
}
