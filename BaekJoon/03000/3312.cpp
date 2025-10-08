// Title : Similarity
// Link  : https://www.acmicpc.net/problem/3312 
// Time  : 172 ms
// Memory: 15796 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s2 >> s1;
  int n1 = s1.size(), n2 = s2.size();

  int64_t sum = 0;

  vector<int> arr;
  for (int b = 0; b < 26; b++) {
    arr.assign(n2 + 1, 0);
    for (int i = 0; i < n2; i++) {
      int x = s2[i] - 'a';
      arr[i + 1] = arr[i];
      if (x == b) ++arr[i + 1];
    }

    for (int i = 0; i < n1; i++) {
      int rem = n1 - i;
      int l = n2 - min<int>(n2, rem);
      int r = min<int>(i, n2 - 1);
      int x = s1[i] - 'a';
      if (x == b) sum += arr[r + 1] - arr[l];
    }
  }
  cout << sum;

  return 0;
}