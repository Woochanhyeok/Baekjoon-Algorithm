#include <iostream>
#include <queue>
using namespace std;

int box[101][101][101];
bool visited[101][101][101];
int dx[8] = { 1,-1,0,0,0,0 };
int dy[8] = { 0,0,1,-1,0,0 };
int dz[8] = { 0,0,0,0,1,-1 };
int M, N, H;
class Location {
public:
	int h;
	int m;
	int n;
	Location(int h, int m, int n) {
		this->h = h;
		this->m = m;
		this->n = n;
	}
};

bool check() {
	bool result = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (box[i][j][k] == 0)
					result = false;
			}
		}
	}
	return result;
}

int main()
{
	cin >> N >> M >> H;
	queue<Location> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				int num; cin >> num;
				box[i][j][k] = num;
				if (num == 1) {
					Location location(i, j, k);
					q.push(location);
				}
			}
		}
	}
	int count = 0;
	while (!q.empty()) {
		int num = q.size();
		vector<Location> tempLocation;
		for (int i = 0; i < num; i++) {
			Location location = q.front();
			int h = location.h, m = location.m, n = location.n;
			q.pop();
			for (int j = 0; j < 6; j++) {
				int nextH = h + dx[j], nextM = m + dy[j], nextN = n + dz[j];
				if (nextH < 0 || nextH >= H || nextM < 0 || nextM >= M || nextN < 0 || nextN >= N) continue;
				if (box[nextH][nextM][nextN] == 0 && !visited[nextH][nextM][nextN]) {
					visited[nextH][nextM][nextN] = true;
					box[nextH][nextM][nextN] = 1;
					Location nextLocation(nextH, nextM, nextN);
					tempLocation.push_back(nextLocation);
				}
			}
		}
		
		for (int i = 0; i < tempLocation.size(); i++) {
			q.push(tempLocation[i]);
		}
		
		count++;
	}
	count--;

	if (!check())
		count = -1;
	cout << count;
}