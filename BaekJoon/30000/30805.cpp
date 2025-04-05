// Title : 사전 순 최대 공통 부분 수열
// Link  : https://www.acmicpc.net/problem/30805
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bitset<101> b1, b2;
  int n;
  cin >> n;
  vector<int> s1(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> s1[i];
    b1.set(s1[i]);
  }
  cin >> n;
  vector<int> s2(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> s2[i];
    b2.set(s2[i]);
  }

  vector<int> ans;
  vector<int>::iterator it1 = s1.begin(), it2 = s2.begin();
  b1 &= b2;
  for (int i = 100; i > 0; i--) {
    if (!b1.test(i)) continue;
    for (;;) {
      auto it1_tmp = find(it1, s1.end(), i);
      auto it2_tmp = find(it2, s2.end(), i);
      if (it1_tmp != s1.end() && it2_tmp != s2.end()) {
        ans.push_back(i);
        it1 = it1_tmp + 1;
        it2 = it2_tmp + 1;
      } else {
        break;
      }
    }
    if (it1 == s1.end() || it2 == s2.end()) break;
  }

  cout << ans.size() << endl;
  if (!ans.empty()) {
    for (int v : ans) cout << v << " ";
    cout << endl;
  }

  return 0;
}
