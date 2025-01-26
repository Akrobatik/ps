#include <bits/stdc++.h>

using namespace std;

int s1[1000], s2[1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t t;
  cin >> t;
  int n, m;
  cin >> n;
  int* e1 = s1;
  for (int i = 0; i < n; i++) cin >> *e1++;
  cin >> m;
  int* e2 = s2;
  for (int i = 0; i < m; i++) cin >> *e2++;

  map<int64_t, int64_t> m1;
  for (int i = 0; i < n; i++) {
    int64_t sum = 0;
    int* ptr = s1 + i;
    while (ptr != e1) {
      sum += *ptr++;
      if (auto it = m1.find(sum); it != m1.end()) {
        it->second++;
      } else {
        m1.insert({sum, 1});
      }
    }
  }

  map<int64_t, int64_t> m2;
  for (int i = 0; i < m; i++) {
    int64_t sum = 0;
    int* ptr = s2 + i;
    while (ptr != e2) {
      sum += *ptr++;
      if (auto it = m2.find(sum); it != m2.end()) {
        it->second++;
      } else {
        m2.insert({sum, 1});
      }
    }
  }

  int64_t ans = 0;
  for (auto [v, cnt] : m1) {
    if (auto it = m2.find(t - v); it != m2.end()) ans += cnt * it->second;
  }

  cout << ans << "\n";

  return 0;
}
