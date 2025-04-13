// Title : 소수 세기
// Link  : https://www.acmicpc.net/problem/29261 
// Time  : 20 ms
// Memory: 21264 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
bool seive[3000001];
bool visited[3000001];
int memo[3000001];

int Calc(int n) {
  if (n == 2 || n == 3) return 1;

  if (visited[n]) return memo[n];
  visited[n] = true;

  int px, py, half = n >> 1;
  for (auto p : primes) {
    if (p > half) break;
    if (seive[n - p - 1]) continue;
    px = p, py = n - p - 1;
  }
  return memo[n] = Calc(px) + Calc(py) + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (!seive[i]) primes.push_back(i);
    for (auto p : primes) {
      if (i * p > n) break;
      seive[i * p] = true;
      if (i % p == 0) break;
    }
  }
  cout << Calc(n);

  return 0;
}
