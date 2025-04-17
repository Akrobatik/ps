// Title : Hide those Letters
// Link  : https://www.acmicpc.net/problem/9949 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int k = 1;; k++) {
    char a, b;
    cin >> a >> b;
    if (a == '#' && b == '#') break;

    if (k != 1) cout << "\n";
    cout << "Case " << k << "\n";

    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
      getline(cin, s);
      for (auto& c : s) {
        char cc = tolower(c);
        if (cc == a || cc == b) c = '_';
      }
      cout << s << "\n";
    }
  }

  return 0;
}
