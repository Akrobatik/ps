// Title : 알고리즘 수업 - 버블 정렬 2
// Link  : https://www.acmicpc.net/problem/23969 
// Time  : 116 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        if (--k == 0) {
          for (auto e : arr) cout << e << " ";
          return 0;
        }
      }
    }
  }
  cout << "-1";

  return 0;
}
