#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, k;
  cin >> n >> d >> k;

  int maxx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    maxx = max<int>(maxx, x);
  }

  int sum = 0, cnt = 0;
  for (int i = 0; i < d; i++) {
    if (sum + maxx > k) {
      sum = 0, ++cnt;
    }
    sum += maxx;
  }
  cout << cnt;

  return 0;
}
