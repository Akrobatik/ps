// Title : 체스평평설
// Link  : https://www.acmicpc.net/problem/33961 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n < 3) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n";
  if (n % 3 == 0) {
    cout << "1 1\n"
            "2 2\n"
            "1 3\n"
            "2 1\n"
            "1 2\n"
            "2 3\n";
  } else if (n % 3 == 1) {
    cout << "1 1\n"
            "2 2\n"
            "1 4\n"
            "2 3\n"
            "1 2\n"
            "2 1\n"
            "1 3\n"
            "2 4\n";
  } else {
    cout << "1 5\n"
            "2 4\n"
            "1 3\n"
            "2 1\n"
            "1 2\n"
            "2 3\n"
            "1 1\n"
            "2 2\n"
            "1 4\n"
            "2 5\n";
  }
  for (int i = 3 + (n % 3); i < n; i += 3) {
    cout << "1 " << i + 1 << "\n";
    cout << "2 " << i + 2 << "\n";
    cout << "1 " << i + 3 << "\n";
    cout << "2 " << i + 1 << "\n";
    cout << "1 " << i + 2 << "\n";
    cout << "2 " << i + 3 << "\n";
  }

  return 0;
}
