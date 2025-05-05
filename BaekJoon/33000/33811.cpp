// Title : Split The GSHS 4
// Link  : https://www.acmicpc.net/problem/33811 
// Time  : 4 ms
// Memory: 2912 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  string_view sv = s;
  int cur = 0, maxx = 0;
  for (int i = 3; i < n; i++) {
    auto sub = sv.substr(i - 3, 4);
    int add = (sub == "SSHS" ? 1 : sub == "GSHS" ? -1 : 0);
    cur = max<int>(cur + add, 0);
    maxx = max<int>(maxx, cur);
  }
  cout << maxx;

  return 0;
}
