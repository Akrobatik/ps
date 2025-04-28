// Title : 약수들의 합
// Link  : https://www.acmicpc.net/problem/9506 
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n && n != -1) {
    int limit = sqrt(n), sum = 0;
    vector<int> arr;
    for (int i = 1; i <= limit; i++) {
      if (n % i) continue;

      if (i * i == n) {
        sum += i;
        arr.push_back(i);
      } else {
        sum += i + n / i;
        arr.push_back(i);
        arr.push_back(n / i);
      }
    }

    if (sum - n == n) {
      sort(arr.begin(), arr.end());
      arr.pop_back();
      cout << n << " = " << arr[0];
      for (int i = 1; i < arr.size(); i++) {
        cout << " + " << arr[i];
      }
      cout << "\n";
    } else {
      cout << n << " is NOT perfect.\n";
    }
  }

  return 0;
}
