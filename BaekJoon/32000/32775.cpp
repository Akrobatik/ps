// Title : 가희와 4시간의 벽 1
// Link  : https://www.acmicpc.net/problem/32775 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << (a <= b ? "high speed rail" : "flight");

  return 0;
}