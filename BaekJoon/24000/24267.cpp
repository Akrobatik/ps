// Title : 알고리즘 수업 - 알고리즘의 수행 시간 6
// Link  : https://www.acmicpc.net/problem/24267 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int64_t sum = 1;
  for (int i = 0; i < 3; i++) {
    sum = sum * (n - i) / (i + 1);
  }
  cout << sum << "\n3";

  return 0;
}
