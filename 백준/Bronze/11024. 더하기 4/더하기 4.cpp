#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  string s;
  cin >> t;
  getline(cin, s);
  while (t--) {
    getline(cin, s);
    istringstream iss(s);
    int64_t sum = 0, n;
    while (iss >> n) sum += n;
    cout << sum << "\n";
  }

  return 0;
}
