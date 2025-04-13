// Title : 언젠가 정렬이 될 수 있으면 좋겠네.
// Link  : https://www.acmicpc.net/problem/31003 
// Time  : 712 ms
// Memory: 28424 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(int a, int b) {
  while (b) a %= b, swap(a, b);
  return a == 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int> memo(n);
  vector<vector<int>> edges(n);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (!Check(arr[i], arr[j])) {
        ++memo[i];
        edges[j].push_back(i);
      }
    }
  }

  auto Cmp = [&](int lhs, int rhs) {
    return arr[lhs] > arr[rhs];
  };

  priority_queue<int, vector<int>, decltype(Cmp)> pq(Cmp);
  for (int i = 0; i < n; i++) {
    if (memo[i]) continue;
    pq.push(i);
  }

  while (!pq.empty()) {
    int cur = pq.top();
    pq.pop();

    cout << arr[cur] << " ";
    for (auto nxt : edges[cur]) {
      if (--memo[nxt] == 0) {
        pq.push(nxt);
      }
    }
  }

  return 0;
}
