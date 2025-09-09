// Title : 카드 정렬하기
// Link  : https://www.acmicpc.net/problem/1715 
// Time  : 24 ms
// Memory: 3684 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
  while (n--) {
    int x;
    cin >> x;
    pq.push(x);
  }

  int64_t sum = 0;
  while (pq.size() >= 2) {
    int64_t x = pq.top();
    pq.pop();
    int64_t y = pq.top();
    pq.pop();

    sum += x + y;
    pq.push(x + y);
  }
  cout << sum;

  return 0;
}