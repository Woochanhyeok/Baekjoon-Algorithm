#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Location {
public:
    int n;
    int m;
    bool isCrashed;
    int level;

    Location(int n, int m, bool isCrashed, int level) {
        this->n = n;
        this->m = m;
        this->isCrashed = isCrashed;
        this->level = level;
    }
};

int main()
{
    int N, M; cin >> N >> M;
    int maze[1001][1001];
    bool visited[2][1001][1001]; fill(visited[0][0], visited[2][0], false);
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for (int i = 0; i < N; i++) {
        string temp = ""; cin >> temp;
        for (int j = 0; j < temp.length(); j++) {
            maze[i][j] = temp[j] - '0';
        }
    }
    queue<Location> q;
    Location start(0, 0, false, 0);
    q.push(start);
    visited[0][0][0] = true; visited[1][0][0] = true;

    while (!q.empty()) {
        Location current = q.front(); q.pop();
        if (current.n == N - 1 && current.m == M - 1) {
            cout << 1;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nextN = current.n + dx[i], nextM = current.m + dy[i];
            Location next(nextN, nextM, current.isCrashed, current.level+1);
            if (next.n == N - 1 && next.m == M - 1) {
                cout << ++next.level;
                return 0;
            }
            if (next.n < 0 || next.n >= N || next.m < 0 || next.m >= M) continue;
            if (next.isCrashed && visited[1][nextN][nextM]) continue;
            if (!next.isCrashed && visited[0][nextN][nextM]) continue;
            //다음 칸이 벽이 아니고 방문한 적 없을 경우
            if (maze[nextN][nextM] == 0) {
                q.push(next);
                if (!next.isCrashed)
                    visited[0][nextN][nextM] = true;
                else
                    visited[1][nextN][nextM] = true;
            }
            //다음 칸이 벽이고 현재 경로가 벽을 부신 적이 없을 경우에 뿌시는 경우
            else if (maze[nextN][nextM] == 1 && next.isCrashed == false) {
                visited[1][nextN][nextM] = true;
                next.isCrashed = true;
                q.push(next);
            }
        }
    }
    cout << -1;

}