// Title : APC2shake!
// Link  : https://www.acmicpc.net/problem/31925 
// Time  : 4 ms
// Memory: 3132 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, string>> arr;
  while (n--) {
    string a, b, c;
    int d, e;
    cin >> a >> b >> c >> d >> e;
    if (b != "jaehak") continue;
    if (c != "notyet") continue;
    if (1 <= d && d <= 3) continue;
    arr.push_back({e, a});
  }
  sort(arr.begin(), arr.end());
  arr.resize(min<int>(arr.size(), 10));
  sort(arr.begin(), arr.end(), [](const pair<int, string>& lhs, const pair<int, string>& rhs) {
    return lhs.second.compare(rhs.second) < 0;
  });

  cout << arr.size() << "\n";
  for (auto [_, s] : arr) cout << s << "\n";

  return 0;
}
