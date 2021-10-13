#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> answer;
	int N; cin >> N;
	vector<int> target;
	for (int i = 0; i < N; i++) {
		int num = 0; cin >> num;
		target.push_back(num);
	}
	sort(target.begin(), target.end());
	int M; cin >> M;
	vector<int> arr;
	for (int i = 0; i < M; i++) {
		int num = 0; cin >> num;
		arr.push_back(num);
	}

	for (int i = 0; i < M; i++) {
		int num = arr[i];

		int result = (upper_bound(target.begin(), target.end(), num) - target.begin()) - (lower_bound(target.begin(), target.end(), num) - target.begin());
		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}