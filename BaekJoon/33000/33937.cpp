// Title : 태권도와 복싱을 합한 운동
// Link  : https://www.acmicpc.net/problem/33937 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  int i1 = -1;
  for (int i = 1; i < s1.size(); i++) {
    if (Check(s1[i - 1]) && !Check(s1[i])) {
      i1 = i;
      break;
    }
  }

  int i2 = -1;
  for (int i = 1; i < s2.size(); i++) {
    if (Check(s2[i - 1]) && !Check(s2[i])) {
      i2 = i;
      break;
    }
  }

  if (i1 == -1 || i2 == -1) {
    cout << "no such exercise";
  } else {
    s1.resize(i1), s2.resize(i2);
    cout << s1 << s2;
  }

  return 0;
}
