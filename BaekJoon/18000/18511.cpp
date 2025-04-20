// Title : 큰 수 구성하기
// Link  : https://www.acmicpc.net/problem/18511 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int ans;
vector<int> arr;

void Traverse(int x, int n) {
  if (x > n) return;
  ans = max<int>(ans, x);

  x *= 10;
  for (auto e : arr) {
    Traverse(x + e, n);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  arr.resize(k);
  for (auto& e : arr) cin >> e;
  Traverse(0, n);
  cout << ans;

  return 0;
}
