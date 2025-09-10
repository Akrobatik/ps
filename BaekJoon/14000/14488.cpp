// Title : 준오는 급식충이야!!
// Link  : https://www.acmicpc.net/problem/14488 
// Time  : 56 ms
// Memory: 10732 KB

#include <bits/stdc++.h>

using namespace std;

int64_t ReadT() {
  string s;
  cin >> s;
  auto pos = s.find('.');
  if (pos == string::npos) return stoll(s) * 10000;
  string l = s.substr(0, pos);
  string r = s.substr(pos + 1);
  int64_t lv = stoll(l), rv = stoll(r);
  for (int i = r.size(); i < 4; i++) rv *= 10;
  return lv * 10000 + rv;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t t = ReadT();

  vector<int64_t> arr(n), axr(n);
  for (auto& e : arr) cin >> e, e *= 10000;
  for (auto& e : axr) cin >> e;

  map<__int128_t, pair<int, int>> mp;
  for (int i = 0; i < n; i++) {
    __int128_t mid = arr[i];
    __int128_t dlt = (__int128_t)axr[i] * t;
    __int128_t l = mid - dlt, r = mid + dlt;
    mp[l].first += 1, mp[r].second -= 1;
  }

  int cur = 0;
  for (auto [key, val] : mp) {
    if ((cur += val.first) == n) {
      cout << "1";
      return 0;
    }
    cur -= val.second;
  }
  cout << "0";

  return 0;
}
