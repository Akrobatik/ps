#include <bits/stdc++.h>

using namespace std;

bool memo[42];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int now = 0;
    int score = 0;
    for (char c : s) {
      if (c == 'O') {
        score += ++now;
      } else {
        now = 0;
      }
    }
    cout << score << "\n";
  }

  return 0;
}
