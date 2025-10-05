// Title : 순회강연
// Link  : https://www.acmicpc.net/problem/2109 
// Time  : 4 ms
// Memory: 2224 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [d, p] : arr) cin >> p >> d;
  sort(arr.begin(), arr.end());

  int64_t sum = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto [d, p] : arr) {
    sum += p;
    pq.push(p);
    while (pq.size() > d) sum -= pq.top(), pq.pop();
  }
  cout << sum;

  return 0;
}