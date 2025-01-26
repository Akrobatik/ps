#include <bits/stdc++.h>

using namespace std;

struct Surface {
  int64_t value;
  int idx;

  auto operator<=>(const Surface& rhs) const {
    return value <=> rhs.value;
  }
};

template <int N>
  requires(1 <= N && N <= 3 || N == 5)
int64_t GetMax(Surface v[6]) {
  if constexpr (N == 1) {
    return v[0].value;
  } else if constexpr (N == 2) {
    if (v[0].idx + v[1].idx != 5) {
      return v[0].value + v[1].value;
    } else {
      return v[0].value + v[2].value;
    }
  } else if constexpr (N == 3) {
    for (int i = 0; i < 6; i++) {
      for (int j = i + 1; j < 6; j++) {
        for (int k = j + 1; k < 6; k++) {
          if (v[i].idx + v[j].idx != 5 && v[i].idx + v[k].idx != 5 && v[j].idx + v[k].idx != 5)
            return v[i].value + v[j].value + v[k].value;
        }
      }
    }
  } else {
    int64_t vv = 0;
    for (int i = 0; i < 5; i++) vv += v[i].value;
    return vv;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  Surface v[6];
  cin >> n;
  for (int i = 0; i < 6; i++) {
    v[i].idx = i;
    cin >> v[i].value;
  }
  sort(begin(v), end(v));

  int64_t result;
  if (n == 1) {
    result = GetMax<5>(v);
  } else if (n == 2) {
    int64_t v2 = GetMax<2>(v);
    int64_t v3 = GetMax<3>(v);
    result = v2 * 4 + v3 * 4;
  } else {
    int64_t v1 = GetMax<1>(v);
    int64_t v2 = GetMax<2>(v);
    int64_t v3 = GetMax<3>(v);

    int64_t n1 = (n - 2) * ((n - 2) + (n - 1) * 4);
    int64_t n2 = (n - 2) * 4 + (n - 1) * 4;
    int64_t n3 = 4;

    result = v1 * n1 + v2 * n2 + v3 * n3;
  }

  cout << result << endl;

  return 0;
}