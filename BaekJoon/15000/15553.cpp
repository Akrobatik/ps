// Title : 난로
// Link  : https://www.acmicpc.net/problem/15553 
// Time  : 20 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, old;
  cin >> n >> k >> old;

  vector<int> arr(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int cur;
    cin >> cur;
    arr[i] = cur - old - 1;
    old = cur;
  }
  sort(arr.begin(), arr.end());

  int sum = n, rem = n - k;
  for (int i = 0; i < rem; i++) {
    sum += arr[i];
  }
  cout << sum;

  return 0;
}