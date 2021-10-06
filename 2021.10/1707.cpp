#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int K; cin >> K;
	vector<string> answer;
	bool visited[20001];
	int level[20001];

	for (int i = 0; i < K; i++) {
		answer.push_back("YES");
	}

	for (int i = 0; i < K; i++) {
		vector<vector<int>> graph(20001);
		fill(level, level + 20001, -1);
		fill(visited, visited + 20001, false);
		int V, E; cin >> V >> E;
		for (int j = 0; j < E; j++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		queue<int> q;
		for (int k = 1; k <= V; k++) {
			if (visited[k]) continue;
			q.push(k); visited[k] = true; level[k] = 0;
			while (!q.empty()) {
				int node = q.front(); q.pop();
				for (int l = 0; l < graph[node].size(); l++) {
					int next = graph[node][l];
					if (level[node] == level[next]) answer[i] = "NO";
					if (!visited[next]) {
						visited[next] = true;
						level[next] = level[node] + 1;
						q.push(next);
					}
				}
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}