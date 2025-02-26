#include <bits/stdc++.h>

using namespace std;

bool memo[1003002];

bool IsPalindrome(int n) {
  vector<int> digits;
  while (n) digits.push_back(n % 10), n /= 10;
  int size = digits.size();
  for (int i = 0; i < (size >> 1); i++) {
    if (digits[i] != digits[size - i - 1]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> vec;
  for (int i = 2; i <= 1003001; i++) {
    if (memo[i]) continue;
    for (int j = (i << 1); j <= 1003001; j += i) memo[j] = true;
    if (IsPalindrome(i)) vec.push_back(i);
  }

  int n;
  cin >> n;
  cout << *lower_bound(vec.begin(), vec.end(), n);

  return 0;
}
