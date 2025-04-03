#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int> psum(n + 1);
  for (int i = 0; i < n; i++) {
    psum[i + 1] = psum[i] + (arr[i] == 1);
  }

  if (psum[n] >= ((n + 1) >> 1)) {
    cout << "0";
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (psum[i] >= ((i + 1) >> 1) || psum[n] - psum[n - i] >= ((i + 1) >> 1)) {
      cout << "1";
      return 0;
    }
  }
  cout << "2";

  return 0;
}
