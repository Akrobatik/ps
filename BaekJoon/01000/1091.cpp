// Title : 카드 섞기
// Link  : https://www.acmicpc.net/problem/1091 
// Time  : 24 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), axr(n), brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  auto Check = [&]() {
    for (int i = 0; i < n; i++) {
      if (i % 3 != arr[i]) return false;
    }
    return true;
  };

  for (int i = 0; i < 510510; i++) {
    if (Check()) {
      cout << i;
      return 0;
    }

    for (int j = 0; j < n; j++) {
      axr[brr[j]] = arr[j];
    }
    swap(arr, axr);
  }
  cout << "-1";

  return 0;
}
