// Title : 역원소 정렬
// Link  : https://www.acmicpc.net/problem/5648 
// Time  : 0 ms
// Memory: 2224 KB

#include <bits/stdc++.h>

using namespace std;

int64_t Read() {
  string s;
  cin >> s;
  while (s.size() >= 2 && s.back() == '0') s.pop_back(); 
  reverse(s.begin(), s.end());
  return stoll(s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n);
  for (auto& e : arr) e = Read();

  sort(arr.begin(), arr.end());
  for (auto e : arr) cout << e << "\n";

  return 0;
}