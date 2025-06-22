// Title : 가장 긴 막대 자석
// Link  : https://www.acmicpc.net/problem/26122 
// Time  : 4 ms
// Memory: 5992 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  vector<int> arr;
  int idx = 0;
  while (idx < n) {
    int nxt = idx;
    while (nxt < n && s[idx] == s[nxt]) ++nxt;
    arr.push_back(nxt - idx);
    idx = nxt;
  }

  int maxx = 0;
  for (int i = 1; i < arr.size(); i++) {
    maxx = max<int>(maxx, min<int>(arr[i - 1], arr[i]));
  }
  cout << (maxx << 1);

  return 0;
}
