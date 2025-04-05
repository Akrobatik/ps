// Title : 더하기 4
// Link  : https://www.acmicpc.net/problem/11024
// Time  : 0 ms
// Memory: 2080 KB

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
