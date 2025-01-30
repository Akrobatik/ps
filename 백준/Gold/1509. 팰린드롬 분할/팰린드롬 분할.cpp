#include <bits/stdc++.h>

using namespace std;

constexpr uint64_t kPrime = 1e9 + 9;
constexpr uint64_t kBase = 91;

template <int N>
struct PolyHashArray {
  constexpr PolyHashArray() : arr() {
    for (int i = 0; i < N; i++) {
      if (i == 0) {
        arr[i] = 1;
      } else {
        arr[i] = (arr[i - 1] * kBase) % kPrime;
      }
    }
  }

  uint64_t arr[N];
};

uint64_t forwards[2501];
uint64_t backwards[2501];
constexpr PolyHashArray<2501> _polyhashes;
const uint64_t* polyhashes = _polyhashes.arr;

int memo[2501];

bool Check(int i, int j) {
  return (forwards[j + 1] + polyhashes[j + 1] * backwards[i]) % kPrime ==
         (forwards[i] + polyhashes[i] * backwards[j + 1]) % kPrime;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    forwards[i + 1] = (forwards[i] + s[i] * polyhashes[i]) % kPrime;
    backwards[i + 1] = (backwards[i] * kBase + s[i]) % kPrime;
  }

  for (int i = 0; i < n; i++) {
    memo[i + 1] = i + 1;
    for (int j = 0; j <= i; j++) {
      if ((j == i || Check(j, i)) && memo[i + 1] > memo[j] + 1) {
        memo[i + 1] = memo[j] + 1;
      }
    }
  }

  cout << memo[n];

  return 0;
}
