// Title : 중앙값의 함정
// Link  : https://www.acmicpc.net/problem/34929 
// Time  : 100 ms
// Memory: 3196 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end(), greater<int>());

  cout << arr[n == 1 ? 0 : 1] << "\n";
  while (arr.size() >= 3) {
    int x = arr.back();
    arr.pop_back();
    int y = arr.back();
    arr.pop_back();
    int z = arr.back();
    arr.pop_back();
    cout << x << " " << y << " " << z << "\n";
    arr.push_back(y);
  }

  return 0;
}