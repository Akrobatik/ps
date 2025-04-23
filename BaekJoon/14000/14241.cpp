// Title : 슬라임 합치기
// Link  : https://www.acmicpc.net/problem/14241 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  priority_queue<int, vector<int>, greater<int>> pq;

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    pq.push(x);
  }

  int sum = 0;
  while (pq.size() != 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    sum += a * b;
    pq.push(a + b);
  }
  cout << sum;

  return 0;
}
