// Title : 시간과 날짜
// Link  : https://www.acmicpc.net/problem/25024 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kDate[] = {
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool CheckT(int h, int m) {
  if (h < 0 || m < 0) return false;
  return h <= 23 && m <= 59;
}

bool CheckD(int m, int d) {
  if (m <= 0 || m > 12 || d <= 0) return false;
  return d <= kDate[m - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (CheckT(a, b) ? "Yes " : "No ")
         << (CheckD(a, b) ? "Yes\n" : "No\n");
  }

  return 0;
}
