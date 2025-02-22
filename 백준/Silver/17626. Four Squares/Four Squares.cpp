#include <bits/stdc++.h>

using namespace std;

constexpr array<int, 223> kSquares = []() {
  array<int, 223> arr;
  for (int i = 1; i <= 223; i++) {
    arr[i - 1] = i * i;
  }
  return arr;
}();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (binary_search(kSquares.begin(), kSquares.end(), n)) {
    cout << '1';
    return 0;
  }

  for (auto v : kSquares) {
    if (binary_search(kSquares.begin(), kSquares.end(), n - v)) {
      cout << '2';
      return 0;
    }
  }

  for (int i = 0; i < kSquares.size(); i++) {
    for (int j = i; j < kSquares.size(); j++) {
      if (binary_search(kSquares.begin(), kSquares.end(), n - kSquares[i] - kSquares[j])) {
        cout << '3';
        return 0;
      }
    }
  }

  cout << '4';
  return 0;
}
