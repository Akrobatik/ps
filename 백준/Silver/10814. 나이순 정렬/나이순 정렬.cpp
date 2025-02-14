#include <bits/stdc++.h>

using namespace std;

tuple<int, int, string> mans[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int age;
    string name;
    cin >> age >> name;
    mans[i] = {age, i, name};
  }
  sort(mans, mans + n);
  for (int i = 0; i < n; i++) cout << get<0>(mans[i]) << " " << get<2>(mans[i]) << "\n";

  return 0;
}
