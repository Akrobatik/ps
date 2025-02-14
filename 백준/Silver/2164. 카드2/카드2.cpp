#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  deque<int> dq(n);
  iota(dq.begin(), dq.end(), 1);

  while (dq.size() != 1) {
    dq.pop_front();
    dq.push_back(dq.front());
    dq.pop_front();
  }
  cout << dq.front();

  return 0;
}
