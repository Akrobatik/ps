// Title : Acentuación del idioma español
// Link  : https://www.acmicpc.net/problem/33883 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  auto Check = [](char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  };

  int nth = 1 + (Check(s.back()) || s.back() == 'n' || s.back() == 's');
  vector<int> arr;
  for (int i = 0; i < s.size(); i++) {
    if (Check(s[i])) arr.push_back(i);
  }

  if (arr.size() < nth) {
    cout << "-1";
  } else {
    cout << arr[arr.size() - nth] + 1;
  }

  return 0;
}
