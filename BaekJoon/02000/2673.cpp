// Title : 교차하지 않는 원의 현들의 최대집합
// Link  : https://www.acmicpc.net/problem/2673 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[100][100] = {};

  int n;
  cin >> n;
  vector<pair<int, int>> lines(n);
  for (auto& [a, b] : lines) {
    cin >> a >> b;
    --a, --b;
    if (a > b) swap(a, b);
  }
  sort(lines.begin(), lines.end());

  auto Check = [&](int a, int b) {
    return binary_search(lines.begin(), lines.end(), make_pair(a, b));
  };

  for (int i = 0; i < 100; i++) {
    for (int j = i; j >= 0; j--) {
      for (int k = j; k < i; k++) {
        memo[j][i] = max<int>(memo[j][i], memo[j][k] + memo[k][i] + Check(j, i));
      }
    }
  }
  cout << memo[0][99];

  return 0;
}