// Title : 교집합 만들기
// Link  : https://www.acmicpc.net/problem/25393 
// Time  : 232 ms
// Memory: 42040 KB

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int minn[1000001], maxx[1000001];
vector<int> arr[1000001];
bool check[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(minn, 0x7F, sizeof(minn));

  int n;
  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r;
    minn[r] = min<int>(minn[r], l);
    maxx[l] = max<int>(maxx[l], r);
    arr[l].push_back(r);
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (!check[l]) {
      check[l] = true;
      sort(arr[l].begin(), arr[l].end());
    }

    if (binary_search(arr[l].begin(), arr[l].end(), r)) {
      cout << "1\n";
    } else if (l >= minn[r] && r <= maxx[l]) {
      cout << "2\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
