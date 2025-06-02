// Title : A+B - 10 (제2편)
// Link  : https://www.acmicpc.net/problem/30924 
// Time  : 856 ms
// Memory: 13676 KB

#include <bits/stdc++.h>

using namespace std;

bool Query(char c, int x) {
  cout << "? " << c << " " << x << endl;

  int res;
  cin >> res;
  return (res != 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mt19937 gen(random_device{}());

  vector<int> arr(10000);
  iota(arr.begin(), arr.end(), 1);
  shuffle(arr.begin(), arr.end(), gen);

  int a, b;
  for (auto e : arr) {
    if (Query('A', e)) {
      a = e;
      break;
    }
  }

  shuffle(arr.begin(), arr.end(), gen);
  for (auto e : arr) {
    if (Query('B', e)) {
      b = e;
      break;
    }
  }

  cout << "! " << a + b << endl;

  return 0;
}
