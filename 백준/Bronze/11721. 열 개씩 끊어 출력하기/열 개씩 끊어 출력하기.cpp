#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int l = 0;
  while (l < s.size()) {
    int r = min<int>(l + 10, s.size());
    cout << string_view(s.begin() + l, s.begin() + r) << "\n";
    l = r;
  }

  return 0;
}
