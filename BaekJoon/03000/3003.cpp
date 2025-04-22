// Title : 킹, 퀸, 룩, 비숍, 나이트, 폰
// Link  : https://www.acmicpc.net/problem/3003 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kArr[] = {1, 1, 2, 2, 2, 8};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 6; i++) {
    int x;
    cin >> x;
    cout << kArr[i] - x << " ";
  }

  return 0;
}
