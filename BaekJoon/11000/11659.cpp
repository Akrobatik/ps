// Title : 구간 합 구하기 4
// Link  : https://www.acmicpc.net/problem/11659
// Time  : 36 ms
// Memory: 2680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[100001];
  int psum[100001];

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int sum = 0;
  for (int i = 1; i <= n; i++) psum[i] = (sum += arr[i]);

  while (m--) {
    int i, j;
    cin >> i >> j;
    cout << psum[j] - psum[i - 1] << "\n";
  }

  return 0;
}
