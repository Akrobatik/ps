// Title : Fridge of Your Dreams
// Link  : https://www.acmicpc.net/problem/11104
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << stoi(s, 0, 2) << "\n";
  }

  return 0;
}
