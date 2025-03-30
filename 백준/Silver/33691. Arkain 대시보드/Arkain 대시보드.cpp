#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, int> hm;
  unordered_set<string> hs;

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    hm[s] = n;
  }

  int k;
  cin >> k;
  while (k--) {
    string s;
    cin >> s;
    hs.insert(s);
  }

  vector<tuple<int, int, string>> arr;
  arr.reserve(100000);
  for (auto [k, v] : hm) {
    arr.push_back({hs.contains(k) ? 0 : 1, v, k});
  }
  sort(arr.begin(), arr.end());
  for (auto e : arr) {
    cout << get<2>(e) << "\n";
  }

  return 0;
}