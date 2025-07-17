// Title : 오디션
// Link  : https://www.acmicpc.net/problem/34068 
// Time  : 48 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ++arr[a - 1];
  }
  sort(arr.begin(), arr.end());

  int64_t sum = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] < arr[i]) continue;
    int d = arr[i - 1] - arr[i] + 1;
    arr[i] += d;
    sum += d;
  }
  cout << sum;

  return 0;
}
