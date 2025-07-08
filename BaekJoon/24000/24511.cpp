// Title : queuestack
// Link  : https://www.acmicpc.net/problem/24511 
// Time  : 40 ms
// Memory: 3332 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n), brr(n);
  queue<int> q;
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i]) continue;
    q.push(brr[i]);
  }

  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    q.push(x);
    cout << (x = q.front(), q.pop(), x) << " ";
  }

  return 0;
}