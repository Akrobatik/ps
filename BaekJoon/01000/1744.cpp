// Title : 수 묶기
// Link  : https://www.acmicpc.net/problem/1744 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr, brr;
  while (n--) {
    int x;
    cin >> x;
    if (x > 0) {
      arr.push_back(x);
    } else {
      brr.push_back(x);
    }
  }

  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end(), greater<>());

  int64_t sum = 0;
  while (arr.size() >= 2) {
    int a = arr.back();
    arr.pop_back();
    int b = arr.back();
    arr.pop_back();
    sum += max<int64_t>((int64_t)a * b, a + b);
  }

  while (brr.size() >= 2) {
    int a = brr.back();
    brr.pop_back();
    int b = brr.back();
    brr.pop_back();
    sum += max<int64_t>((int64_t)a * b, a + b);
  }

  if (!arr.empty()) sum += arr[0];
  if (!brr.empty()) sum += brr[0];

  cout << sum;

  return 0;
}
