// Title : 가로수
// Link  : https://www.acmicpc.net/problem/2485 
// Time  : 12 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  int g = arr[1] - arr[0];
  for (int i = 2; i < n; i++) {
    int d = arr[i] - arr[i - 1];
    g = GCD(d, g);
  }

  int cnt = (arr[n - 1] - arr[0]) / g - n + 1;
  cout << cnt;

  return 0;
}
