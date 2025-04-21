// Title : 다이얼
// Link  : https://www.acmicpc.net/problem/5622 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

  string s;
  cin >> s;
  int sum = 0;
  for (auto c : s) sum += memo[c - 'A'];
  cout << sum;

  return 0;
}
