// Title : 좌표 정렬하기
// Link  : https://www.acmicpc.net/problem/11650
// Time  : 40 ms
// Memory: 2800 KB

#include <bits/stdc++.h>

using namespace std;

pair<int, int> coords[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> coords[i].first >> coords[i].second;
  sort(coords, coords + n);
  for (int i = 0; i < n; i++) cout << coords[i].first << " " << coords[i].second << "\n";

  return 0;
}
