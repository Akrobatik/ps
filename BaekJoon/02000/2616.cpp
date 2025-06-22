// Title : 소형기관차
// Link  : https://www.acmicpc.net/problem/2616 
// Time  : 4 ms
// Memory: 2608 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  int m;
  cin >> m;

  vector<int> fwd(n), bwd(n);
  int maxx = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    cur += arr[i];
    if (i - m >= 0) cur -= arr[i - m];
    maxx = max<int>(maxx, cur);
    fwd[i] = maxx;
  }
  maxx = cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur += arr[i];
    if (i + m < n) cur -= arr[i + m];
    maxx = max<int>(maxx, cur);
    bwd[i] = maxx;
  }

  maxx = cur = 0;
  for (int i = 0; i < m; i++) cur += arr[i];
  for (int i = 1; i + m < n; i++) {
    cur += arr[i + m - 1] - arr[i - 1];
    maxx = max<int>(maxx, cur + fwd[i - 1] + bwd[i + m]);
  }
  cout << maxx;

  return 0;
}
