// Title : 노트북 세 대를 가지고 왔다
// Link  : https://www.acmicpc.net/problem/33515 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << min<int>(a, b);

  return 0;
}
