// Title : 정수 N개의 합
// Link  : https://www.acmicpc.net/problem/15596 
// Time  : 4 ms
// Memory: 13740 KB

#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for (auto e : a) ans += e;
	return ans;
}
