// Title : 순열의 순서
// Link  : https://www.acmicpc.net/problem/1722 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t fact[21] = {1};
  for (int i = 1; i <= 20; i++) {
    fact[i] = fact[i - 1] * i;
  }

  int n, cmd;
  cin >> n >> cmd;
  if (cmd == 1) {
    int64_t k;
    cin >> k;
    --k;
    int arr[20];
    vector<int> cands;
    cands.resize(n);
    iota(cands.begin(), cands.end(), 1);
    for (int i = 0; i < n; i++) {
      int64_t x = fact[n - i - 1];
      int y = k / x;
      k -= x * y;
      arr[i] = cands[y];
      cands.erase(cands.begin() + y);
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
  } else {
    int arr[20];
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> cands;
    cands.resize(n);
    iota(cands.begin(), cands.end(), 1);

    int64_t k = 0;
    for (int i = 0; i < n; i++) {
      int64_t x = fact[n - i - 1];
      auto it = find(cands.begin(), cands.end(), arr[i]);
      k += x * (it - cands.begin());
      cands.erase(it);
    }
    cout << k + 1;
  }

  return 0;
}
