// Title : 첫 번째 문제는 정말 쉬운 문제일까?
// Link  : https://www.acmicpc.net/problem/34071 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  int minn = x, maxx = x;
  while (--n) {
    int y;
    cin >> y;
    minn = min<int>(minn, y);
    maxx = max<int>(maxx, y);
  }
  
  if (minn == x) {
    cout << "ez";
  } else if (maxx == x) {
    cout << "hard";
  } else {
    cout << "?";
  }

  return 0;
}
