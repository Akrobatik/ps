// Title : 제곱 수?
// Link  : https://www.acmicpc.net/problem/34027 
// Time  : 0 ms
// Memory: 2288 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr;
  for (int i = 1; i * i <= kMax; i++) arr.push_back(i * i);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << binary_search(arr.begin(), arr.end(), n) << "\n";
  }

  return 0;
}
