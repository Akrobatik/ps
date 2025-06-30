// Title : 사탕 배달
// Link  : https://www.acmicpc.net/problem/17305 
// Time  : 60 ms
// Memory: 5128 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, w;
  cin >> n >> w;

  vector<int> arr, brr;
  for (int i = 0; i < n; i++) {
    int t, s;
    cin >> t >> s;
    if (t == 3) {
      arr.push_back(s);
    } else {
      brr.push_back(s);
    }
  }

  sort(arr.begin(), arr.end(), greater<int>());
  sort(brr.begin(), brr.end(), greater<int>());

  vector<int64_t> axr(arr.size() + 1);
  for (int i = 0; i < arr.size(); i++) {
    axr[i + 1] = axr[i] + arr[i];
  }

  auto Calc = [&](int rem) {
    return axr[min<int>(arr.size(), rem / 3)] - axr[0];
  };

  int64_t maxx = Calc(w), sum = 0;
  for (auto e : brr) {
    if ((w -= 5) < 0) break;
    sum += e;
    maxx = max<int64_t>(maxx, sum + Calc(w));
  }
  cout << maxx;

  return 0;
}
