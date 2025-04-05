// Title : N과 M （8）
// Link  : https://www.acmicpc.net/problem/15657
// Time  : 4 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int memo[8];
vector<int> arr;

void Print(int i, int j, int m) {
  if (i == m) {
    for (int i = 0; i < m; i++) cout << memo[i] << " ";
    cout << "\n";
    return;
  }

  int na = arr.size();
  for (int k = j; k < na; k++) {
    memo[i] = arr[k];
    Print(i + 1, k, m);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  arr.resize(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  Print(0, 0, m);

  return 0;
}
