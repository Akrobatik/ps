// Title : A+B - 투 스텝
// Link  : https://www.acmicpc.net/problem/31430 
// Time  : 0 ms
// Memory: 4048 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  if (t == 1) {
    int64_t a, b;
    cin >> a >> b;
    string res(13, 'a');
    int64_t x = a + b;
    for (int i = 0; i < 13; i++, x /= 26) {
      res[12 - i] += x % 26;
    }
    cout << res;
  } else {
    string s;
    cin >> s;
    int64_t x = 0;
    for (int64_t i = 0, b = 1; i < 13; i++, b *= 26) {
      x += b * (s[12 - i] - 'a');
    }
    cout << x;
  }

  return 0;
}