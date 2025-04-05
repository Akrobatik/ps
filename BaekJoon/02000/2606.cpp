// Title : 바이러스
// Link  : https://www.acmicpc.net/problem/2606 
// Time  : 0 ms
// Memory: 2024 KB

// 질문글 확인용
// https://www.acmicpc.net/board/view/158476

#include <iostream>
#include <vector>
using namespace std;

int node;
int line;

vector<vector<int>> graph;
vector<bool> visited;
int cnt = 0;
void DFS(int v) {
	if (visited[v]) {
		return;
	}
	visited[v] = true;
	cnt++;
	for (int i : graph[v]) {
		DFS(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node;
	cin >> line;


	graph.resize(node + 1);
	visited = vector<bool>(node + 1, false);

	for (int i = 0; i < line; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	DFS(1);
	cout << cnt - 1;
}
