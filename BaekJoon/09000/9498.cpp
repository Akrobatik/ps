// Title : 시험 성적
// Link  : https://www.acmicpc.net/problem/9498
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n >= 90) {
    cout << "A";
  } else if (n >= 80) {
    cout << "B";
  } else if (n >= 70) {
    cout << "C";
  } else if (n >= 60) {
    cout << "D";
  } else {
    cout << "F";
  }

  return 0;
}
