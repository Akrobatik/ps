// Title : Olympic Ranking
// Link  : https://www.acmicpc.net/problem/23334 
// Time  : 4 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  tuple<int, int, int> best = {-1, -1, -1};
  string bs;
  while (n--) {
    int a, b, c;
    string s;
    cin >> a >> b >> c;
    tuple<int, int, int> sum = {a, b, c};
    cin.ignore();
    getline(cin, s);
    if (best < sum) best = sum, bs = s;
  }
  cout << bs;

  return 0;
}
