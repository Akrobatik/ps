// Title : 조약돌
// Link  : https://www.acmicpc.net/problem/25378 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int sum = 0, cnt = 0;
  set<int> memo;
  for (int i = 0; i < n; i++) {
    ++cnt;
    if (memo.contains(arr[i])) {
      memo.clear();
      sum += cnt - 1;
      cnt = 0;
    } else {
      set<int> nxt;
      for (auto x : memo) {
        if (arr[i] - x > 0) nxt.insert(arr[i] - x);
      }
      nxt.insert(arr[i]);
      memo.swap(nxt);
    }
  }
  cout << sum + cnt;

  return 0;
}
