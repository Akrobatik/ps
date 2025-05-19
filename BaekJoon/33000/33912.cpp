// Title : N거리 건너기
// Link  : https://www.acmicpc.net/problem/33912 
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  --m;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[x - 1] = i;
  }

  int64_t fwd = 0, bwd = 0;
  for (int i = 0, cur = 0; i < m; i++) {
    fwd += (arr[i] - cur + n) % n;
    cur = arr[i];
  }
  for (int i = n - 1, cur = 0; i >= m; i--) {
    bwd += (arr[i] - cur + n) % n;
    cur = arr[i];
  }

  if (fwd == bwd) {
    cout << "EQ";
  } else if (fwd < bwd) {
    cout << "CW";
  } else {
    cout << "CCW";
  }

  return 0;
}