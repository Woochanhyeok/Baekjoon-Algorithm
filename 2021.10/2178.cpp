#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int maze[101][101];
bool visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main()
{
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp = ""; cin >> temp;
        for (int j = 0; j < temp.length(); j++) {
            maze[i][j] = temp[j] - '0';
        }
    }
    int count = 0;
    queue<pair<int,int>> q;
    q.push({ 0,0 });
    while (!q.empty()) {
        count++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == N - 1 && y == M - 1) {
            cout << maze[N - 1][M - 1];
        }

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i]; int nextY = y + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
            if (maze[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                maze[nextX][nextY] = maze[x][y] + 1;
                q.push({ nextX, nextY });
            }
        }
    }
}