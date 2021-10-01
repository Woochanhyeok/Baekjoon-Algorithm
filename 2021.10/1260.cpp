#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[1001];
vector<vector<int>> vec(1001);

void dfs(int node) {
	visited[node] = true;
	cout << node << " ";
	sort(vec[node].begin(), vec[node].end());
	for (int i = 0; i < vec[node].size(); i++) {
		int next = vec[node][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main()
{
	int N, M, V; cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	

	//dfs
	dfs(V);
	cout << endl;
	//bfs
	fill_n(visited, 1001, false);
	queue<int> q;
	q.push(V);
	visited[V] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		sort(vec[node].begin(), vec[node].end());
		for (int i = 0; i < vec[node].size(); i++) {
			int next = vec[node][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}

}