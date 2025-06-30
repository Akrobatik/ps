// Title : 호숫가의 개미굴
// Link  : https://www.acmicpc.net/problem/28325 
// Time  : 36 ms
// Memory: 2564 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int zero = 0;
  int64_t sum = 0;
  vector<bool> arr(n);
  for (int i = 0; i < n; i++) {
    int64_t x;
    cin >> x;
    sum += x;
    if (x == 0) {
      arr[i] = true;
      ++zero;
    }
  }

  if (n == zero) {
    cout << (n >> 1);
    return 0;
  }

  vector<int> axr;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i]) {
      ++cnt;
    } else if (cnt) {
      axr.push_back(cnt);
      cnt = 0;
    }
  }
  if (cnt) axr.push_back(cnt);

  if (arr[0] && arr[n - 1]) {
    axr[0] += axr.back();
    axr.pop_back();
  }
  for (auto e : axr) {
    sum += ((e + 1) >> 1);
  }
  cout << sum;

  return 0;
}
