// Title : 최솟값 찾기
// Link  : https://www.acmicpc.net/problem/11003 
// Time  : 1184 ms
// Memory: 42420 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  deque<int> dq;
  for (int i = 0; i < l; i++) {
    while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
    dq.push_back(i);
    cout << arr[dq.front()] << " ";
  }

  for (int i = l; i < n; i++) {
    while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
    dq.push_back(i);
    int limit = i - l;
    while (dq.front() <= limit) dq.pop_front();
    cout << arr[dq.front()] << " ";
  }

  return 0;
}
