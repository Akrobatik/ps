// Title : 더하기와 나누기
// Link  : https://www.acmicpc.net/problem/28426 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    
  int n;
  cin >> n;
    
  cout << "2 ";
  for (int i = 1; i < n; i++) {
    cout << i * 4 << " ";
  }
    
  return 0;
}