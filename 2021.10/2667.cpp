#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
bool visited[25][25];
vector<vector<int>> v;
int N;
vector<int> result;
void dfs(int x, int y, int size) {
	if (x<0 || x>=N || y<0 || y>=N) return;
	if (!visited[x][y] && v[x][y] == 1) {
		visited[x][y] = true;
		result[size]++;
		dfs(x - 1, y, size);
		dfs(x + 1, y, size);
		dfs(x, y - 1, size);
		dfs(x, y + 1, size);
		
	}
}

int main()
{
	cin >> N;
	result.push_back(0);
	fill(visited[0], visited[0] + 625, false);

	vector<string> str;
	for (int i = 0; i < N; i++) {
		string temp = ""; cin >> temp;
		str.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		vector<int>temp;
		for (int j = 0; j < N; j++) {
			temp.push_back(str[i][j] - '0');
		}
		v.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && v[i][j] == 1) {
				result.push_back(0);
				dfs(i, j,result.size()-1);
				result[0]++;
			}
		}
	}
	sort(result.begin() + 1, result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}