#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> ss(n);
  while (n--) cin >> ss[n];
  sort(ss.begin(), ss.end(), [](const string& lhs, const string& rhs) {
    return lhs.size() != rhs.size() ? lhs.size() < rhs.size() : lhs < rhs;
  });
  string last;
  for (auto& s : ss) {
    if (s.compare(last) != 0) cout << s << "\n";
    last = s;
  }

  return 0;
}
