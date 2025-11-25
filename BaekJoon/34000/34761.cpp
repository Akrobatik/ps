// Title : 같은 배열
// Link  : https://www.acmicpc.net/problem/34761 
// Time  : 56 ms
// Memory: 4564 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n), brr(n << 1);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;

  bool ok = true;
  for (int i = 0; ok && i < n; i++) {
    ok = (arr[i] == brr[i]);
  }

  vector<int8_t> table(n + 1);
  for (auto e : arr) table[e] = 1;

  for (int i = 0; ok && i < n; i++) {
    ok = table[brr[i + n]];
  }

  cout << (ok ? "YES" : "NO");

  return 0;
}