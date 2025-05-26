// Title : 리버스 정렬
// Link  : https://www.acmicpc.net/problem/33986 
// Time  : 16 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ans;

void SortOE(vector<int>& arr) {
  int n = arr.size(), cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += ((arr[i] + i + 1) & 1);
  }

  if (cnt == 0) return;

  if (n != cnt) {
    for (int i = 0; i < cnt; i++) {
      if ((arr[i] + i + 1) & 1) continue;

      int j = i;
      while (!((arr[j] + j + 1) & 1)) j += 2;
      reverse(arr.begin() + i, arr.begin() + j + 1);
      ans.push_back({i + 1, j + 1});
    }
  }

  reverse(arr.begin(), arr.begin() + cnt);
  ans.push_back({1, cnt});
}

void Sort(vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if (arr[i] == i + 1) continue;

    int j = i;
    while (arr[j] != i + 1) ++j;
    reverse(arr.begin() + i, arr.begin() + j + 1);
    ans.push_back({i + 1, j + 1});
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  SortOE(arr);
  Sort(arr);

  cout << ans.size() << "\n";
  for (auto [l, r] : ans) cout << l << " " << r << "\n";

  return 0;
}
