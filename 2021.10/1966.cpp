#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//현재 맨앞의 것보다 중요도가 더 큰게 있는지 확인 => 더 큰게 있으면 false
bool check(queue<pair<int, int>> q) {
	bool result = true;
	pair<int, int> first = q.front(); q.pop();
	int count = q.size();
	for (int i = 0; i < count; i++) {
		if (first.second < q.front().second) {
			result = false;
			break;
		}
		q.pop();
	}
	return result;
}

int main()
{
	int T; cin >> T;
	vector<int> answer;
	for (int i = 0; i < T; i++) {
		int N, M; cin >> N >> M;
		queue<pair<int, int>> q;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			int num = 0; cin >> num;
			q.push({ i,num });
		}
		
		while (v.size() != N) {
			if (check(q)) {
				v.push_back(q.front().first);
				q.pop();
			}
			else {
				pair<int, int> temp = q.front();
				q.pop();
				q.push(temp);
			}
		}

		for (int i = 0; i < N; i++) {
			if (v[i] == M)
				answer.push_back(i+1);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}