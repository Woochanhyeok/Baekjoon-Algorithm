#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int dx[8] = {-2,-1,1,2,-2,-1,1,2};
	int dy[8] = {1,2,2,1,-1,-2,-2,-1};
	int box[301][301];
	bool visited[301][301];
	int T; cin >> T;
	vector<int> answer;

	for (int t = 0; t < T; t++) {
		fill(box[0], box[301], 0);
		fill(visited[0], visited[301], false);
		int result = 0;
		int l; cin >> l;
		pair<int, int> start, finish;
		int num1, num2; cin >> num1 >> num2;
		start.first = num1; start.second = num2;
		cin >> num1 >> num2;
		finish.first = num1; finish.second = num2;

		queue <pair<int, int>> q;
		q.push(start);
		while (!q.empty()) {
			pair<int, int> current = q.front(); q.pop();
			if (current.first == finish.first && current.second == finish.second) {
				result = box[current.first][current.second];
				break;
			}
			for (int i = 0; i < 8; i++) {
				pair<int, int> next;
				next.first = current.first + dx[i]; next.second = current.second + dy[i];
				if (next.first < 0 || next.first >= l || next.second < 0 || next.second >= l) continue;
				
				if (visited[next.first][next.second]) continue;
				q.push(next);
				visited[next.first][next.second] = true;
				box[next.first][next.second] = box[current.first][current.second] + 1;
			}
		}
		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}
