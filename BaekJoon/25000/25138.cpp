// Title : SORT
// Link  : https://www.acmicpc.net/problem/25138 
// Time  : 32 ms
// Memory: 8288 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<string, string>> arr(n);
  for (auto& [cmp, org] : arr) {
    cin >> org;
    cmp.reserve(org.size());
    for (int i = 0; i < org.size(); i++) {
      if (org[i] <= 'k') {
        cmp.push_back(org[i]);
      } else if (org[i] == 'l') {
        if (i + 1 != org.size() && org[i + 1] == 'j') {
          cmp.push_back(org[i++] + 1);
        } else {
          cmp.push_back(org[i]);
        }
      } else if (org[i] == 'm') {
        cmp.push_back(org[i] + 1);
      } else if (org[i] == 'n') {
        if (i + 1 != org.size() && org[i + 1] == 'j') {
          cmp.push_back(org[i++] + 2);
        } else {
          cmp.push_back(org[i] + 1);
        }
      } else {
        cmp.push_back(org[i] + 2);
      }
    }
  }

  sort(arr.begin(), arr.end());
  for (auto& e : arr) cout << e.second << "\n";

  return 0;
}
