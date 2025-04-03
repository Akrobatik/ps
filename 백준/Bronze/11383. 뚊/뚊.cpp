#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  for (auto& s : arr) cin >> s;
  for (int j = 0; j < n; j++) {
    string s;
    cin >> s;
    for (int i = 0; i < m; i++) {
      if (s[i * 2] == s[i * 2 + 1] && s[i * 2] == arr[j][i]) continue;
      cout << "Not Eyfa";
      return 0;
    }
  }
  cout << "Eyfa";

  return 0;
}
