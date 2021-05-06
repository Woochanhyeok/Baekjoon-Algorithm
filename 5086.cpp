#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0; cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num = 0;
		v.push_back(num);
	}

	if (v.size() == 1)
		cout << v[0] * v[0];
	else
		cout << v[0] * v[v.size() - 1];

}