// Title : 최고의 맛집을 찾아서
// Link  : https://www.acmicpc.net/problem/34874 
// Time  : 56 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(m + 1), cnt(m + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[j];
    }

    int maxx = *max_element(arr.begin(), arr.end());
    for (int j = 1; j <= m; j++) {
      cnt[j] += (arr[j] == maxx);
    }
  }

  for (int i = 1; i <= m; i++) {
    cout << n - cnt[i] << " ";
  }

  return 0;
}