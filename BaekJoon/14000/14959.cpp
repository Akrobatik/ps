// Title : Slot Machines
// Link  : https://www.acmicpc.net/problem/14959 
// Time  : 108 ms
// Memory: 9836 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : views::reverse(arr)) cin >> e;

  vector<int> table(n);
  for (int i = 1, idx = 0; i < n; i++) {
    while (idx && arr[i] != arr[idx]) idx = table[idx - 1];
    if (arr[i] == arr[idx]) table[i] = ++idx;
  }

  int minn = INT_MAX, bk, bp;
  for (int i = 1; i <= n; i++) {
    int k = n - i, p = i - table[i - 1];
    if (minn > k + p) minn = k + p, bk = k, bp = p;
  }

  cout << bk << " " << bp;

  return 0;
}
