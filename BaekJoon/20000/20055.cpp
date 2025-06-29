// Title : 컨베이어 벨트 위의 로봇
// Link  : https://www.acmicpc.net/problem/20055 
// Time  : 156 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  int sz = n << 1;
  vector<bool> check(sz);
  vector<int> arr(sz);
  for (auto& e : arr) cin >> e;

  int head = 0, step = 0, cnt = 0;
  while (cnt < k) {
    if (--head < 0) head += sz;
    ++step;

    int up = head, down = (head + n - 1) % sz;
    if (check[down]) check[down] = false;
    for (int i = n - 1; i >= 0; i--) {
      int l = (head + i) % sz, r = (l + 1) % sz;
      if (check[l] && !check[r] && arr[r]) {
        check[l] = false, check[r] = true;
        if (--arr[r] == 0) ++cnt;
      }
    }
    if (check[down]) check[down] = false;

    if (arr[up]) {
      check[up] = true;
      if (--arr[up] == 0) ++cnt;
    }
  }
  cout << step;

  return 0;
}