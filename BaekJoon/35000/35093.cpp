// Title : Jumbled Packets
// Link  : https://www.acmicpc.net/problem/35093 
// Time  : 40 ms
// Memory: 14576 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string cmd, s;
  int n;
  cin >> cmd >> n >> s;
  if (cmd[0] == 'E') {
    if (n == 1) {
      cout << s;
    } else if (n == 2) {
      if (s[0] == s[1]) {
        cout << s;
      } else {
        cout << '2' << s[0];
      }
    } else if (n == 3) {
      int x = s[0];
      bool ok = true;
      for (int i = 0; ok && i < 3; i++) {
        ok = (s[i] == x);
      }

      if (ok) {
        cout << s;
      } else {
        int y = s[0] ^ s[1] ^ s[2], z = 0;
        while (s[z] != y) ++z;
        cout << '2' << (char)(y ^ 1) << z;
      }
    } else if (n == 4) {
      int x = s[0];
      bool ok = true;
      for (int i = 0; ok && i < 4; i++) {
        ok = (s[i] == x);
      }

      if (ok) {
        cout << s;
      } else if (s == "0111") {
        cout << "2000";
      } else if (s == "1110") {
        cout << "2222";
      } else {
        x = 0;
        for (int i = 0; i < 3; i++) {
          int v = s[i] - '0';
          x += v << i;
        }
        int y1 = x % 3, y2 = x / 3;
        cout << '2' << y1 << y2;
        for (int i = 3; i < n; i++) cout << s[i];
      }
    } else {
      int x = 0;
      for (int i = 0; i < 3; i++) {
        int v = s[i] - '0';
        x += v << i;
      }
      int y1 = x % 3, y2 = x / 3;
      cout << '2' << y1 << y2;
      for (int i = 3; i < n; i++) cout << s[i];
    }
  } else {
    if (n == 1) {
      cout << s;
    } else if (n == 2) {
      if (s[0] == s[1]) {
        cout << s;
      } else {
        if (s[0] < s[1]) swap(s[0], s[1]);
        cout << s[1] << (char)(s[1] ^ 1);
      }
    } else if (n == 3) {
      int x = s[0];
      bool ok = true;
      for (int i = 0; ok && i < 3; i++) {
        ok = (s[i] == x);
      }

      if (ok) {
        cout << s;
      } else {
        auto Check = [&]() {
          return s[0] == '2' && s[1] != '2';
        };

        while (!Check()) {
          rotate(s.begin(), s.begin() + 1, s.end());
        }

        int y = s[1], z = s[2] - '0';
        for (int i = 0; i < 3; i++) {
          cout << (char)(y ^ (i == z ? 1 : 0));
        }
      }
    } else if (n == 4) {
      int x = s[0];
      bool ok = true;
      for (int i = 0; ok && i < 4; i++) {
        ok = (s[i] == x);
      }

      if (ok) {
        cout << s;
      } else if (s == "2222") {
        cout << "1110";
      } else {
        auto Check = [&]() {
          if (s[0] != '2') return false;
          for (int i = 3; i < n; i++) {
            if (s[i] == '2') return false;
          }
          return true;
        };

        while (!Check()) {
          int st = 1;
          while (s[st] != '2') ++st;
          rotate(s.begin(), s.begin() + st, s.end());
        }

        if (s == "2000") {
          cout << "0111";
        } else {
          x = 0;
          for (int i = 1; i < 3; i++) {
            int v = s[i] - '0';
            x += v * (i == 1 ? 1 : 3);
          }
          int y0 = x & 1, y1 = (x >> 1) & 1, y2 = (x >> 2) & 1;
          cout << y0 << y1 << y2;
          for (int i = 3; i < n; i++) cout << s[i];
        }
      }
    } else {
      auto Check = [&]() {
        if (s[0] != '2') return false;
        for (int i = 3; i < n; i++) {
          if (s[i] == '2') return false;
        }
        return true;
      };

      while (!Check()) {
        int st = 1;
        while (s[st] != '2') ++st;
        rotate(s.begin(), s.begin() + st, s.end());
      }

      int x = 0;
      for (int i = 1; i < 3; i++) {
        int v = s[i] - '0';
        x += v * (i == 1 ? 1 : 3);
      }
      int y0 = x & 1, y1 = (x >> 1) & 1, y2 = (x >> 2) & 1;
      cout << y0 << y1 << y2;
      for (int i = 3; i < n; i++) cout << s[i];
    }
  }

  return 0;
}