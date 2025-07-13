// Title : 연산 추가하기
// Link  : https://www.acmicpc.net/problem/34055 
// Time  : 144 ms
// Memory: 5520 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, h;
  cin >> n >> h;
  vector<pair<int, int>> arr(n);
  for (auto& [l, r] : arr) cin >> l >> r;
  sort(arr.begin(), arr.end());

  vector<int> brr;
  int st = 1, len;
  for (auto [l, r] : arr) {
    len = l - st;
    if (len > 0) brr.push_back(len);
    st = max<int>(st, r + 1);
  }
  len = h - st + 1;
  if (len > 0) brr.push_back(len);

  int nb = brr.size();
  sort(brr.begin(), brr.end());
  vector<int> bxr(nb + 1);
  for (int i = 0; i < nb; i++) {
    bxr[i + 1] = bxr[i] + brr[i];
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;

    int cnt = 0;
    auto it = lower_bound(brr.begin(), brr.end(), x);
    if (it != brr.end()) {
      int i = it - brr.begin();
      cnt = bxr[nb] - bxr[i] - (x - 1) * (nb - i);
    }
    cout << cnt << "\n";
  }

  return 0;
}