// Title : 거울
// Link  : https://www.acmicpc.net/problem/34201 
// Time  : 28 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, s;
  cin >> n >> s;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  auto Move = [&](int64_t x) {
    s = (x << 1) - s;
  };

  if (n & 1) {
    int64_t x = arr.back();
    arr.pop_back();
    Move(x);
    --n;
  }

  int half = n >> 1;
  for (int i = 0; i < half; i++) {
    Move(arr[i]);
    Move(arr[n - i - 1]);
  }

  cout << s;

  return 0;
}