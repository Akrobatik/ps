// Title : 수열과 헌팅
// Link  : https://www.acmicpc.net/problem/20495 
// Time  : 152 ms
// Memory: 6836 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr[i] = {a - b, a + b, i};
  }

  vector<int> fwd(n), bwd(n);
  priority_queue<int> pq;
  int cnt = 1;
  sort(arr.begin(), arr.end());
  for (auto [l, r, i] : arr) {
    while (!pq.empty() && -pq.top() < l) pq.pop(), ++cnt;
    pq.push(-r);
    fwd[i] = cnt;
  }
  while (!pq.empty()) pq.pop();

  cnt = n;
  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    return get<1>(lhs) > get<1>(rhs);
  });
  for (auto [l, r, i] : arr) {
    while (!pq.empty() && pq.top() > r) pq.pop(), --cnt;
    pq.push(l);
    bwd[i] = cnt;
  }

  for (int i = 0; i < n; i++) cout << fwd[i] << " " << bwd[i] << "\n";

  return 0;
}