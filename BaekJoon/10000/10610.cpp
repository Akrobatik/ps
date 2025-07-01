// Title : 30
// Link  : https://www.acmicpc.net/problem/10610 
// Time  : 4 ms
// Memory: 2300 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int sum = 0, zero = 0;
  for (auto c : s) sum += c - '0', zero += (c == '0');

  if (sum % 3 == 0 && zero) {
    sort(s.begin(), s.end(), greater<char>());
    cout << s;
  } else {
    cout << "-1";
  }

  return 0;
}
