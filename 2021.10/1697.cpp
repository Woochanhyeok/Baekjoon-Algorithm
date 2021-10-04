#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K; cin >> N >> K;
	bool visited[100001]; fill_n(visited, 100001, false);

	queue<int> q; q.push(N);
	int count = 0;
	while(!q.empty()) {
		int num = q.size();
		for (int i = 0; i < num; i++) {
			int current = q.front();
			q.pop();
			if (current == K) {
				cout << count;
				return 0;
			}
			if (current < 0 || current > 100001) continue;
			if (current - 1 >= 0 && !visited[current - 1]) {
				visited[current - 1] = true;
				q.push(current - 1);
			}
			if (current+1 <= 100001 && !visited[current + 1]) {
				visited[current + 1] = true;
				q.push(current + 1);
			}
				
			if (current*2 <= 100001 && !visited[current * 2]) {
				visited[current * 2] = true;
				q.push(current * 2);
			}
		}
		count++;
	}
}