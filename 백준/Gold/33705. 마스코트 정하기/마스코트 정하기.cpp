#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = arr[i - 1] + (x == 1);
  }

  if (arr[n] >= ((n + 1) >> 1)) {
    cout << "0";
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (arr[i] >= ((i + 1) >> 1) || arr[n] - arr[n - i] >= ((i + 1) >> 1)) {
      cout << "1";
      return 0;
    }
  }
  cout << "2";

  return 0;
}
