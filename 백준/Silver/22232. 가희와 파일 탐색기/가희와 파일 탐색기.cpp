#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<string, int, string>> files(n);
  while (n--) {
    string s;
    cin >> s;
    auto it = s.find('.');
    files[n] = {s.substr(0, it), 1, s.substr(it + 1)};
  }

  set<string> exts;
  while (m--) {
    string s;
    cin >> s;
    exts.insert(s);
  }

  for (auto& [a, b, c] : files) b = !exts.contains(c);
  sort(files.begin(), files.end());
  for (auto& [a, b, c] : files) cout << a << "." << c << "\n" ;

  return 0;
}
