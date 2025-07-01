// Title : 라면 사기 (Small)
// Link  : https://www.acmicpc.net/problem/18185 
// Time  : 0 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, b = 3, c = 2;
  cin >> n;
  vector<int> arr(n + 2);
  for (int i = 0; i < n; i++) cin >> arr[i];

  int64_t sum = 0;
  if (b <= c) {
    for (int i = 0; i < n; i++) {
      sum += (int64_t)arr[i] * b;
    }
  } else {
    int bc = b + c;
    int bcc = bc + c;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        if (arr[i + 1] <= arr[i + 2]) {
          int cut = min<int>({arr[i], arr[i + 1]});
          sum += (int64_t)cut * bcc;
          arr[i] -= cut;
          arr[i + 1] -= cut;
          arr[i + 2] -= cut;
        } else {
          int cut = min<int>(arr[i], arr[i + 1] - arr[i + 2]);
          sum += (int64_t)cut * bc;
          arr[i] -= cut;
          arr[i + 1] -= cut;
        }
      }
      sum += (int64_t)arr[i] * b;
    }
  }
  cout << sum;

  return 0;
}
