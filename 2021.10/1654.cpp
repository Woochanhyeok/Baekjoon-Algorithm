#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long K, N; cin >> K >> N;
	vector<int> lan;
	for (int i = 0; i < K; i++) {
		int num = 0; cin >> num;
		lan.push_back(num);
	}

	long long start = 1, end = *max_element(lan.begin(), lan.end());
	long long result = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;
		int total = 0;
		for (int i = 0; i < K; i++) {
			long long num = lan[i];
			int count = 0;
			num -= mid;
			while (num >= 0) {
				count++;
				num -= mid;
			}
			total += count;
		}
		if (total < N) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}

	cout << result;
}