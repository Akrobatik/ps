// Title : 부분합
// Link  : https://www.acmicpc.net/problem/1806
// Time  : 8 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  vector<int> seq;
  seq.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }

  int sum = 0;
  int minn = INT_MAX;
  auto b = seq.begin();
  auto e = b;
  for (;;) {
    if (sum < s) {
      if (e == seq.end()) break;
      sum += *(e++);
    } else {
      minn = min<int>(minn, distance(b, e));
      sum -= *(b++);
    }
  }

  cout << (minn != INT_MAX ? minn : 0) << endl;

  return 0;
}
