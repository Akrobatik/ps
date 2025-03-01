#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  map<int, int> memo;
  int sum = 0;
  while (n--) {
    int a;
    cin >> a;

    int rem = a;
    auto it = memo.lower_bound(a);
    while (rem && it != memo.end()) {
      int cut = min<int>(rem, it->second);
      sum -= cut;
      rem -= cut;
      if ((it->second -= cut) == 0) it = memo.erase(it);
    }

    memo[a] += a;
    sum += a;
  }
  cout << sum;

  return 0;
}
