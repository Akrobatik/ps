#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int Calc(const vector<int>& arr, int s, int n) {
  memo.clear();
  for (int i = 0; i < n; i++) {
    int e = arr[s + i];
    auto it = lower_bound(memo.begin(), memo.end(), e);
    if (it != memo.end()) {
      *it = e;
    } else {
      memo.push_back(e);
    }
  }
  return memo.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n << 1), brr(n << 1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i + n] = arr[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> brr[i];
    brr[i + n] = brr[i];
  }

  int as = 0, bs = 0;
  for (int i = 0; i < n; i++) {
    as = max<int>(as, Calc(arr, i, n));
    bs = max<int>(bs, Calc(brr, i, n));
  }

  if (as == bs) {
    cout << "Both Win!";
  } else if (as > bs) {
    cout << "YJ Win!";
  } else {
    cout << "HG Win!";
  }

  return 0;
}