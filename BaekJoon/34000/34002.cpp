// Title : 임스의 잠수맵
// Link  : https://www.acmicpc.net/problem/34002 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, s, v, l;
  cin >> a >> b >> c >> s >> v >> l;

  int rem = (250 - l) * 100;
  int sum = 0;
  for (int i = 0; i < v && rem > 0; i++) {
    int maxx = c * 30;
    if (rem > maxx) {
      sum += 30;
      rem -= maxx;
    } else {
      int cut = (rem + c - 1) / c;
      sum += cut;
      rem = 0;
    }
  }

  for (int i = 0; i < s && rem > 0; i++) {
    int maxx = b * 30;
    if (rem > maxx) {
      sum += 30;
      rem -= maxx;
    } else {
      int cut = (rem + b - 1) / b;
      sum += cut;
      rem = 0;
    }
  }

  if (rem > 0) {
    int cut = (rem + a - 1) / a;
    sum += cut;
  }

  cout << sum;

  return 0;
}
