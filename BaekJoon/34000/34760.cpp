// Title : 코끼리 15마리가 앞으로 돌진하면 어떻게 막을 건데
// Link  : https://www.acmicpc.net/problem/34760 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[15];
  for (auto& e : arr) cin >> e;

  int maxx = *max_element(arr, arr + 15);
  for (int i = 0 ; i < 14; i++) {
    if (arr[i] == maxx) {
      ++maxx;
      break;
    }
  }
  cout << maxx;

  return 0;
}