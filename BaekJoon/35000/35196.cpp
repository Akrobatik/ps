// Title : Entropy Evasion
// Link  : https://www.acmicpc.net/problem/35196 
// Time  : 16 ms
// Memory: 13808 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);

  auto Query = [&]() -> int {
    int mv = INT_MIN, ml, mr;
    int cv = 0, cp = 1;
    for (int i = 1; i <= n; i++) {
      int val = arr[i] ? -1 : 1;
      if (cv < 0) {
        cv = val, cp = i;
      } else {
        cv += val;
      }

      int len = i - cp + 1;
      if (mv < cv || (mv == cv && (mr - ml + 1) < len)) {
        mv = cv, ml = cp, mr = i;
      }
    }

    cout << ml << " " << mr << endl;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }

    int p;
    cin >> p;
    return p;
  };

  while (Query() < 70);

  return 0;
}