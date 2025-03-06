#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size(), na = 0;
  for (char c : s) na += (c == 'a');
  int cnt = 0;
  for (int i = 0; i < na; i++) cnt += (s[i] == 'a');
  s += s;
  int maxx = cnt;
  for (int i = 0; i < n; i++) {
    cnt += ((s[i + na] == 'a') - (s[i] == 'a'));
    if (maxx < cnt) maxx = cnt;
  }
  cout << na - maxx;

  return 0;
}
