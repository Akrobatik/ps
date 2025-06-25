// Title : 백신 개발
// Link  : https://www.acmicpc.net/problem/30090 
// Time  : 248 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

string s[9];

int Calc(const vector<int>& arr) {
  string str;
  for (auto e : arr) {
    auto& ss = s[e];
    int ns = str.size();
    int len = min<int>(ns, ss.size());
    string_view sv1(str), sv2(ss);
    while (len > 0 && sv1.substr(ns - len) != sv2.substr(0, len)) --len;
    str.append(ss.substr(len));
  }
  return str.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<int> arr(n);
  iota(arr.begin(), arr.end(), 0);

  int minn = INT_MAX;
  do {
    minn = min<int>(minn, Calc(arr));
  } while (next_permutation(arr.begin(), arr.end()));

  cout << minn;

  return 0;
}
