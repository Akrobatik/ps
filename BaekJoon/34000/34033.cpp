// Title : 공금 횡령
// Link  : https://www.acmicpc.net/problem/34033 
// Time  : 140 ms
// Memory: 9948 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  map<string, int> mp;
  while (n--) {
    int x;
    string s;
    cin >> s >> x;
    mp[s] = x + x / 20;
  }

  int cnt = 0;
  while (m--) {
    int x;
    string s;
    cin >> s >> x;
    cnt += (mp[s] < x);
  }
  cout << cnt;

  return 0;
}
