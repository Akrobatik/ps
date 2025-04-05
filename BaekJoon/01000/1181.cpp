// Title : 단어 정렬
// Link  : https://www.acmicpc.net/problem/1181
// Time  : 16 ms
// Memory: 3976 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> ss(n);
  for (int i = 0; i < n; i++) cin >> ss[i];
  sort(ss.begin(), ss.end(), [](const string& lhs, const string& rhs) {
    return lhs.size() != rhs.size() ? lhs.size() < rhs.size() : lhs < rhs;
  });

  cout << ss.front() << "\n";
  for (int i = 1; i < n; i++) {
    if (ss[i - 1].compare(ss[i]) != 0) cout << ss[i] << "\n";
  }

  return 0;
}
