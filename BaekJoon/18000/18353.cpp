// Title : 병사 배치하기
// Link  : https://www.acmicpc.net/problem/18353 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = lower_bound(arr.begin(), arr.end(), x, greater<>());
    if (it != arr.end()) {
      *it = x;
    } else {
      arr.push_back(x);
    }
  }

  cout << n - arr.size();

  return 0;
}
