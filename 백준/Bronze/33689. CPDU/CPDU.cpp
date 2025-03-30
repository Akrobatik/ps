#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    string s;
    cin >> s;
    cnt += (s[0] == 'C');
  }
  cout << cnt;

  return 0;
}