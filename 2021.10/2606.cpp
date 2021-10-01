#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	vector<vector<int>> v(N+1);
	bool visited[101]; fill_n(visited, 101, false);
	queue<int> q;
	int result = 0;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (visited[i])
			result++;
	}
	cout << result;

}