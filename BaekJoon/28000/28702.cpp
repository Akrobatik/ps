// Title : FizzBuzz
// Link  : https://www.acmicpc.net/problem/28702
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    bool ok = true;
    for (char c : s) {
      if ('0' <= c && c <= '9') continue;
      ok = false;
      break;
    }

    if (ok) {
      int v = stoi(s) - i + 3;
      bool b3 = v % 3 == 0;
      bool b5 = v % 5 == 0;
      if (b3 && b5) {
        cout << "FizzBuzz";
      } else if (b3) {
        cout << "Fizz";
      } else if (b5) {
        cout << "Buzz";
      } else {
        cout << v;
      }
      break;
    }
  }

  return 0;
}
