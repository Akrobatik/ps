#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> jewelry(n);
  for (int i = 0; i < n; i++) cin >> jewelry[i].first >> jewelry[i].second;
  sort(jewelry.begin(), jewelry.end());

  vector<int> bags(k);
  for (int i = 0; i < k; i++) cin >> bags[i];
  sort(bags.begin(), bags.end());

  int64_t sum = 0;
  priority_queue<int> pq;
  auto j_it = jewelry.begin(), j_end = jewelry.end();
  for (int bag : bags) {
    while (j_it != j_end && j_it->first <= bag) pq.push((j_it++)->second);
    if (pq.empty()) continue;
    sum += pq.top();
    pq.pop();
  }

  cout << sum;

  return 0;
}
