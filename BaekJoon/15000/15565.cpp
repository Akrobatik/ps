// Title : 귀여운 라이언
// Link  : https://www.acmicpc.net/problem/15565 
// Time  : 24 ms
// Memory: 5220 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '1') arr.push_back(i);
  }

  int minn = INT_MAX;
  for (int i = 0; i + k <= arr.size(); i++) {
    minn = min<int>(minn, arr[i + k - 1] - arr[i] + 1);
  }
  cout << (minn != INT_MAX ? minn : -1);

  return 0;
}
