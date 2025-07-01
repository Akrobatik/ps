// Title : 2025는 무엇이 특별할까?
// Link  : https://www.acmicpc.net/problem/33541 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;
  for (int i = 32; i < 100; i++) {
    int sqr = i * i;
    int sum = sqr / 100 + sqr % 100;
    if (i == sum) arr.push_back(sqr);
  }

  int x;
  cin >> x;
  auto it = upper_bound(arr.begin(), arr.end(), x);
  cout << (it != arr.end() ? *it : -1);

  return 0;
}
