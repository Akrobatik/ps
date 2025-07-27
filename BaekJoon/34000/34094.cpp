// Title : 골드리치의 비밀 금고
// Link  : https://www.acmicpc.net/problem/34094 
// Time  : 276 ms
// Memory: 10156 KB

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

  if (arr.back() == 0) {
    cout << "0\n";
    for (auto e : arr) cout << e << " ";
    return 0;
  }

  deque<int> dq;

  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == cur) {
      arr[i] = -1;
      if (cur & 1) {
        dq.push_front(cur);
      } else {
        dq.push_back(cur);
      }
      ++cur;
    }
  }
  cout << dq.size() + 1 << "\n";
  for (auto e : dq) cout << e << " ";
  for (auto e : arr) {
    if (e == -1) continue;
    cout << e << " ";
  }

  return 0;
}
