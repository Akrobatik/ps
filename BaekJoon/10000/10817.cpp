// Title : 세 수
// Link  : https://www.acmicpc.net/problem/10817 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[3];
  for (auto& e : arr) cin >> e;
  sort(arr, arr + 3);
  cout << arr[1];

  return 0;
}
