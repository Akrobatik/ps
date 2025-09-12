// Title : Messi Gimossi
// Link  : https://www.acmicpc.net/problem/17297 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char kStr[] = "Messi Gimossi ";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t m;
  cin >> m;

  int idx = 0;
  vector<int64_t> arr{6, 14};
  while (arr[++idx] <= m) arr.push_back(arr[idx - 1] + arr[idx]);

  while (m > 14) {
    auto it = upper_bound(arr.rbegin(), arr.rend(), m, greater<int64_t>());
    m -= *it;
  }

  char ch = kStr[m - 1];
  if (ch == ' ') {
    cout << "Messi Messi Gimossi";
  } else {
    cout << ch;
  }

  return 0;
}
