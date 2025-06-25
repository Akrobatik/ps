// Title : 사람의 수
// Link  : https://www.acmicpc.net/problem/1206 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int Read() {
  int a, b;
  char c;
  cin >> a >> c >> b;
  return a * 1000 + b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) e = Read();

  auto Check = [&](int x) {
    for (auto e : arr) {
      int y = e * x;
      int z = ((y / 1000 + (y % 1000 ? 1 : 0)) * 1000) / x;
      if (z == e) continue;
      return false;
    }
    return true;
  };

  for (int i = 1; i <= 1000; i++) {
    if (Check(i)) {
      cout << i;
      break;
    }
  }

  return 0;
}
