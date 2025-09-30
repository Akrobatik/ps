// Title : 와우산 스탬프 투어
// Link  : https://www.acmicpc.net/problem/34543 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kTable[6] = {
    0, 10, 20, 50, 60, 120};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, w;
  cin >> n >> w;

  cout << max<int>(kTable[n] - (w > 1000 ? 15 : 0), 0);

  return 0;
}