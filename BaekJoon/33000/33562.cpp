// Title : shapex
// Link  : https://www.acmicpc.net/problem/33562
// Time  : 4 ms
// Memory: 2172 KB

#include <bits/stdc++.h>

using namespace std;

struct Shape {
  void Parse(const string& s) {
    layers.clear();
    layers.push_back(s);

    // layers.clear();
    // stringstream ss(s);
    // string layer;
    // while (getline(ss, layer, ':')) {
    //   layers.push_back(layer);
    // }
  }

  pair<Shape, Shape> Split() const {
    Shape left, right;
    for (const auto& layer : layers) {
      string l = "----" + layer.substr(4, 4);
      string r = layer.substr(0, 4) + "----";
      if (l != "--------") left.layers.push_back(l);
      if (r != "--------") right.layers.push_back(r);
    }
    return {left, right};
  }

  Shape Rotate(int k) const {
    Shape res;
    for (const auto& layer : layers) {
      string s = layer;
      for (int i = 0; i < k; i++) {
        s = {s[6], s[7], s[0], s[1], s[2], s[3], s[4], s[5]};
      }
      res.layers.push_back(s);
    }
    return res;
  }

  Shape Merge(const Shape& other) const {
    Shape res;
    if (layers.empty() || other.layers.empty()) return res;

    int h1 = layers.size(), h2 = other.layers.size();
    int hb = 0;
    bool ok = true;
    for (int h = h1 - 1; h >= 0; h--) {
      for (int i = 0; i + h < h1 && i < h2; i++) {
        for (int j = 0; j < 8; j += 2) {
          if (layers[i + h][j] != '-' && other.layers[i][j] != '-') {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }

      if (!ok) {
        hb = h + 1;
        break;
      }
    }

    for (const auto& layer : layers) {
      res.layers.push_back(layer);
    }

    for (int i = 0; i + hb < 4 && i < h2; i++) {
      if (i + hb < h1) {
        for (int j = 0; j < 8; j++) {
          if (other.layers[i][j] == '-') continue;
          res.layers[i + hb][j] = other.layers[i][j];
        }
      } else {
        res.layers.push_back(other.layers[i]);
      }
    }
    return res;
  }

  Shape Colorize(char color) const {
    Shape res;
    for (const auto& layer : layers) {
      string s = layer;
      for (int i = 0; i < 8; i += 2) {
        if (s[i] != '-') s[i + 1] = color;
      }
      res.layers.push_back(s);
    }
    return res;
  }

  void Print() const {
    if (layers.empty()) {
      cout << "None";
      return;
    }

    for (int i = 0; i < layers.size(); i++) {
      if (i) cout << ":";
      cout << layers[i];
    }
  }

  vector<string> layers;
};

Shape regs[101];

// Shape Combine(Shape& a, Shape& b) {
//   if (a.empty() || b.empty()) {
//     return Shape();
//   }

//   int a_size = a.size(), b_size = b.size();
//   int x = a_size + 1;

//   while (x > 1) {
//     int y = x - 1;
//     bool invalid = false;

//     for (int i = 0; i < b_size; ++i) {
//       if (invalid) {
//         break;
//       }

//       int level = y + i;

//       if (level > a_size) {
//         continue;
//       }

//       for (int j = 0; j < 4; ++j) {
//         if (b[i][j].first != ' ' && a[level - 1][j].first != ' ') {
//           invalid = true;
//           break;
//         }
//       }
//     }

//     if (!invalid) {
//       x = y;
//     } else {
//       break;
//     }
//   }

//   Shape result(max(a_size, x + b_size - 1), Layer(4, {' ', ' '}));

//   for (int i = 0; i < a_size; ++i) {
//     result[i] = a[i];
//   }

//   for (int i = 0; i < b_size; ++i) {
//     int y = x + i - 1;

//     if (y >= result.size()) {
//       continue;
//     }

//     for (int j = 0; j < 4; ++j) {
//       if (b[i][j].first != ' ') {
//         result[y][j] = b[i][j];
//       }
//     }
//   }

//   if (result.size() > 4) {
//     result.resize(4);
//   }

//   if (all_of(result.begin(), result.end(), [](Layer& layer) {
//         return all_of(layer.begin(), layer.end(),
//                       [](Cell& cell) { return cell.first == ' '; });
//       })) {
//     return Shape();
//   }

//   return result;
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    regs[i].Parse(s);
  }

  while (m--) {
    int t;
    cin >> t;
    switch (t) {
      case 1: {
        int i, j, k;
        cin >> i >> j >> k;
        auto [l, r] = regs[i].Split();
        regs[j] = l;
        regs[k] = r;
      } break;
      case 2: {
        int i, j, k;
        cin >> i >> j >> k;
        regs[j] = regs[i].Rotate(k);
      } break;
      case 3: {
        int i, j, k;
        cin >> i >> j >> k;
        regs[k] = regs[i].Merge(regs[j]);
      } break;
      case 4: {
        int i, j;
        char k;
        cin >> i >> j >> k;
        regs[j] = regs[i].Colorize(k);
      } break;
    }
  }

  regs[100].Print();

  return 0;
}
