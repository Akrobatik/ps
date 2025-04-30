// Title : 수강변경
// Link  : https://www.acmicpc.net/problem/23305 
// Time  : 200 ms
// Memory: 5928 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ++memo[x];
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    --memo[x];
  }

  int sum = 0;
  for (int i = 1; i <= 1000000; i++) {
    sum += max<int>(memo[i], 0);
  }
  cout << sum;

  return 0;
}
