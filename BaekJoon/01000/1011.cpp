// Title : Fly me to the Alpha Centauri
// Link  : https://www.acmicpc.net/problem/1011
// Time  : 0 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int d = y - x;
    int peek = (int)floor(sqrt((double)d));
    cout << peek * 2 - 1 + (int)ceil(double(d - peek * peek) / (double)peek) << endl;
  }

  return 0;
}