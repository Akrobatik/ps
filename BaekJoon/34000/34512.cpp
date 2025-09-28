// Title : 소수제합
// Link  : https://www.acmicpc.net/problem/34512 
// Time  : 48 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

const string kStr[7] = {
    "",
    "",
    "-1",
    "2 5 29",
    "2 2 3 17",
    "2 2 2 3 3",
    "2 2 3 3 3 5",
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n <= 6) {
    cout << kStr[n];
    return 0;
  }

  if (n & 1) {
    for (int i = 0; i < 3; i++) cout << "2 ";
    for (int i = 3; i < n; i++) cout << "3 ";
  } else {
    for (int i = 0; i < 6; i++) cout << "2 ";
    for (int i = 6; i < n; i++) cout << "3 ";
  }

  return 0;
}