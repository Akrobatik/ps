// Title : The Clocks
// Link  : https://www.acmicpc.net/problem/5520 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kTable[9][10] = {
    {1, 2, 1, 2, 2, -1, 1, -1, 0, 8},
    {1, 1, 1, 1, 1, 1, 2, 0, 2, 0},
    {1, 2, 1, -1, 2, 2, 0, -1, 1, 8},
    {1, 1, 2, 1, 1, 0, 1, 1, 2, 0},
    {1, 2, 1, 2, -1, 2, 1, 2, 1, 4},
    {2, 1, 1, 0, 1, 1, 2, 1, 1, 0},
    {1, -1, 0, 2, 2, -1, 1, 2, 1, 8},
    {2, 0, 2, 1, 1, 1, 1, 1, 1, 0},
    {0, -1, 1, -1, 2, 2, 1, 2, 1, 8},
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int arr[10];
  for (auto& e : arr) cin >> e, e %= 4;
  arr[9] = 1;

  int axr[9];
  for (int i = 0; i < 9; i++) {
    int x = 0;
    for (int j = 0; j < 10; j++) {
      x += arr[j] * kTable[i][j];
    }
    if ((x %= 4) < 0) x += 4;
    axr[i] = x;
  }

  vector<int> ans;
  for (int i = 0; i < 9; i++) {
    while (axr[i]--) cout << i + 1 << " ";
  }

  return 0;
}