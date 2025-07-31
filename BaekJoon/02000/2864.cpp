// Title : 5와 6의 차이
// Link  : https://www.acmicpc.net/problem/2864 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;
  for (auto& c : a) {
    if (c == '6') c = '5';
  }
  for (auto& c : b) {
    if (c == '6') c = '5';
  }
  int minn = stoi(a) + stoi(b);

  for (auto& c : a) {
    if (c == '5') c = '6';
  }
  for (auto& c : b) {
    if (c == '5') c = '6';
  }
  int maxx = stoi(a) + stoi(b);

  cout << minn << " " << maxx;

  return 0;
}
