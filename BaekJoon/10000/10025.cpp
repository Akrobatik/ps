// Title : 게으른 백곰
// Link  : https://www.acmicpc.net/problem/10025 
// Time  : 24 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int arr[1000002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  while (n--) {
    int a, b;
    cin >> a >> b;
    arr[b + 1] = a;
  }
  partial_sum(arr, arr + 1000002, arr);

  k = min<int>(k * 2 + 1, 1000001);
  int maxx = 0;
  for (int i = k; i <= 1000001; i++) {
    maxx = max<int>(maxx, arr[i] - arr[i - k]);
  }
  cout << maxx;

  return 0;
}
