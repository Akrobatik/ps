// Title : 가장 긴 증가하는 부분 수열 2
// Link  : https://www.acmicpc.net/problem/12015
// Time  : 144 ms
// Memory: 8292 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> vec;
  while (n--) {
    int v;
    cin >> v;
    auto it = lower_bound(vec.begin(), vec.end(), v);
    if (it != vec.end()) {
      *it = v;
    } else {
      vec.push_back(v);
    }
  }

  cout << vec.size();

  return 0;
}
