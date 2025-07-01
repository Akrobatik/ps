// Title : 소트
// Link  : https://www.acmicpc.net/problem/1083 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  int s;
  cin >> s;

  auto Find = [&](int i) {
    int res = -1;
    for (int j = 1; j <= s && i + j < n; j++) {
      int k = i + j;
      if (arr[i] >= arr[k]) continue;
      if (res == -1 || arr[k] > arr[res]) res = k;
    }
    return res;
  };

  for (int i = 0; i < n && s > 0; i++) {
    int j = Find(i);
    while (i < j) {
      swap(arr[j - 1], arr[j]);
      --j, --s;
    }
  }

  for (auto e : arr) cout << e << " ";

  return 0;
}
