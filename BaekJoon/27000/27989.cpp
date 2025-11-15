// Title : 가장 큰 증가하는 부분 수열 2
// Link  : https://www.acmicpc.net/problem/27989 
// Time  : 160 ms
// Memory: 20768 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t sum = 0;
  map<int64_t, int64_t> mp;
  while (n--) {
    int64_t x;
    cin >> x;

    int64_t rem = x;
    auto it = mp.lower_bound(x);
    while (rem > 0 && it != mp.end()) {
      int64_t cut = min<int64_t>(rem, it->second);
      rem -= cut, sum -= cut;
      if ((it->second -= cut) == 0) it = mp.erase(it);
    }
    sum += x;
    mp[x] += x;
  }
  cout << sum;

  return 0;
}