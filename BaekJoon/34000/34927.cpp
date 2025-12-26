// Title : 박스 쌓기
// Link  : https://www.acmicpc.net/problem/34927 
// Time  : 56 ms
// Memory: 3192 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int64_t acc = 0, cnt = 0;
  for (auto e : arr) {
    if (acc <= e) {
      acc += e;
      ++cnt;
    }
  }
  cout << cnt;

  return 0;
}