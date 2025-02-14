#include <bits/stdc++.h>

using namespace std;

int memo[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    for (char c : s) {
      for (int i = 0; i < n; i++) cout << c;
    }
    cout << "\n";
  }

  return 0;
}
