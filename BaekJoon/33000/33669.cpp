// Title : 짬뽕 369
// Link  : https://www.acmicpc.net/problem/33669
// Time  : 8 ms
// Memory: 2212 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(int x) {
  return x == 3 || x == 6 || x == 9;
}

string Under100() {
  ostringstream oss;
  oss << "12JJAM45PPONG78JJAM";
  bool flip = true;
  for (int i = 10; i < 100; i++) {
    bool b1 = Check(i / 10), b2 = Check(i % 10);
    if (b1 && b2) {
      oss << "JJAMPPONG";
    } else if (b1 || b2) {
      oss << (flip ? "PPONG" : "JJAM");
      flip = !flip;
    } else {
      oss << i;
    }
  }
  return oss.str();
}

int64_t CalcNext(int64_t unit, int digits, bool head) {
  int64_t nxt;
  if (head) {
    nxt = unit * 585;
  } else {
    nxt = unit * digits * 70 + unit * 135;
  }
  return nxt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  s.reserve(10000);

  string u100 = Under100();
  string_view u100sv = u100;

  int64_t a = 285, b = 420;
  vector<int64_t> arr{0, 19, 360};
  for (int i = 3; i < 18; i++) {
    int64_t x = arr.back() + a * 9 + b * i;
    arr.push_back(x);
    a *= 10, b *= 10;
  }

  int t;
  cin >> t;
  while (t--) {
    int64_t l, r;
    cin >> l >> r;
    --l;
    if (l < 360) {
      int rr = min<int64_t>(r, 360);
      cout << u100sv.substr(l, rr - l);
      if (r <= 360) {
        cout << "\n";
        continue;
      }
      l = 360;
    }

    auto rit = lower_bound(arr.rbegin(), arr.rend(), l, greater<>());
    int digits = arr.rend() - rit;
    int64_t x = 1, p = *rit;
    for (int i = 1; i < digits; i++) x *= 10;

    int64_t bx = x, xx = x;
    for (int i = digits; i >= 3; i--) {
      uint64_t unit = xx / 100;
      for (;;) {
        bool head = Check(x / bx);
        int64_t nxt = CalcNext(unit, digits, head);

        if (p + nxt > l) break;

        x += xx;
        p += nxt;
      }

      xx /= 10;
    }

    s.clear();
    l -= p, r -= p;
    bool flip = false, b1 = Check(x / bx);
    while (s.size() < r) {
      bool b2 = Check(x % 10);
      if (b1 && b2) {
        s.append("JJAMPPONG");
      } else if (b1 || b2) {
        s.append(flip ? "PPONG" : "JJAM");
        flip = !flip;
      } else {
        s.append(to_string(x));
      }
      ++x;
    }

    string_view sv = s;
    cout << sv.substr(l, r - l) << "\n";
  }

  return 0;
}
