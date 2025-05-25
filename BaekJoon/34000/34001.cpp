// Title : 임스의 일일 퀘스트
// Link  : https://www.acmicpc.net/problem/34001 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr tuple<int, int, int> kQuest[] = {
    {200, 210, 220},
    {210, 220, 225},
    {220, 225, 230},
    {225, 230, 235},
    {230, 235, 245},
    {235, 245, 250},
    {260, 265, 270},
    {265, 270, 275},
    {270, 275, 280},
    {275, 280, 285},
    {280, 285, 290},
    {285, 290, 295},
    {290, 295, 300},
};

int Calc(int lv, int l, int m, int r) {
  if (lv < l) return 0;
  if (lv < m) return 500;
  if (lv < r) return 300;
  return 100;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int lv;
  cin >> lv;

  for (int i = 0; i < 13; i++) {
    auto [l, m, r] = kQuest[i];
    cout << Calc(lv, l, m, r) << (i == 5 ? "\n" : " ");
  }

  return 0;
}
