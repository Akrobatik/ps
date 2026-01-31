// Title : 일곱 난쟁이
// Link  : https://www.acmicpc.net/problem/2309 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr(9);
  for (auto& e : arr) cin >> e;

  vector<int8_t> idx(9, 1);
  idx[0] = idx[1] = 0;

  do {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
      if (idx[i]) sum += arr[i];
    }

    if (sum == 100) break;
  } while (next_permutation(idx.begin(), idx.end()));

  vector<int> ans;
  for (int i = 0; i < 9; i++) {
    if (idx[i]) ans.push_back(arr[i]);
  }
  sort(ans.begin(), ans.end());

  for (auto e : ans) cout << e << "\n";

  return 0;
}