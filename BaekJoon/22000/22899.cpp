// Title : 오렌지컵 출제하기
// Link  : https://www.acmicpc.net/problem/22899 
// Time  : 60 ms
// Memory: 9036 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<vector<int>> items(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    items[arr[i] - 1].push_back(x);
  }

  sort(items.begin(), items.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
    return lhs.size() > rhs.size();
  });
  for (auto& e : items) sort(e.begin(), e.end(), greater<>());

  int64_t sum = 0;
  priority_queue<int> kpq;
  priority_queue<int, vector<int>, greater<int>> cpq;
  for (int i = 0; i < n; i++) {
    while (!items.empty() && items.back().empty()) items.pop_back();
    for (auto& e : items) cpq.push(e.back()), e.pop_back();
    while (kpq.size() != k && !cpq.empty()) {
      int cx = cpq.top();
      cpq.pop();
      kpq.push(cx);
      sum += cx;
    }
    while (!kpq.empty() && !cpq.empty() && kpq.top() > cpq.top()) {
      int kx = kpq.top(), cx = cpq.top();
      kpq.pop(), cpq.pop();
      sum += cx - kx;
      kpq.push(cx), cpq.push(kx);
    }

    cout << (kpq.size() == k ? sum : -1) << " ";
  }

  return 0;
}