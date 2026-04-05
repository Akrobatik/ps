// Title : It's Mooin' Time IV
// Link  : https://www.acmicpc.net/problem/35338 
// Time  : 4 ms
// Memory: 2648 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, k;
  cin >> t >> k;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int key = 0;
    for (auto& c : views::reverse(s)) {
      c ^= key;
      if (c == 'O') key ^= 2;
    }

    cout << "YES\n";
    if (k) cout << s << "\n";
  }

  return 0;
}