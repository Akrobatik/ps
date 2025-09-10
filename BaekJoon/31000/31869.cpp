// Title : 선배님 밥 사주세요!
// Link  : https://www.acmicpc.net/problem/31869 
// Time  : 0 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<string, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  for (auto& [s, wd, p] : arr) {
    int w, d;
    cin >> s >> w >> d >> p;
    wd = w * 7 + d - 7;
  }

  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    int x;
    cin >> s >> x;
    mp[s] = x;
  }

  int axr[70] = {};
  for (auto& [s, wd, p] : arr) {
    int x = mp[s];
    axr[wd] |= (p <= x);
  }

  int maxx = 0, cur = 0;
  for (int i = 0; i < 70; i++) {
    cur = (axr[i] ? cur + 1 : 0);
    maxx = max<int>(maxx, cur);
  }
  cout << maxx;

  return 0;
}
