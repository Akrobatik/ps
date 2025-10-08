// Title : 이 별은 무슨 색일까
// Link  : https://www.acmicpc.net/problem/30676 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x;
  cin >> x;
  if (x < 425) {
    cout << "Violet";
  } else if (x < 450) {
    cout << "Indigo";
  } else if (x < 495) {
    cout << "Blue";
  } else if (x < 570) {
    cout << "Green";
  } else if (x < 590) {
    cout << "Yellow";
  } else if (x < 620) {
    cout << "Orange";
  } else {
    cout << "Red";
  }

  return 0;
}