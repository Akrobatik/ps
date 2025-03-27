#include <bits/stdc++.h>

using namespace std;

int arr[1000000];
int memo[1000001];
int ans[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int64_t cnt = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] != 1) ++cnt, sum += arr[i];
  }

  int64_t avg = cnt ? sum / cnt : 0;
  for (int i = 0; i < n; i++) {
    int x = avg < arr[i] ? 1 : arr[i];
    if (x > m) {
      cout << "-1";
      return 0;
    }
    ++memo[x];
  }

  for (int i = 1, j = 0; i <= m; i++) {
    while (memo[i]--) arr[j++] = i;
  }

  int l = 0;
  for (int i = 0; i < n; i++) {
    int r = arr[i];
    while (l < r) ans[l++] = n - i;
  }

  for (int i = 0; i < m; i++) cout << ans[i] << " ";

  return 0;
}
