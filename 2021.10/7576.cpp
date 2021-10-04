#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N;
bool check(int box[101][101]) {
    bool result = true;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (box[i][j] == 0)
                result = false;
        }
    }
    return result;
}
int main()
{
    int box[101][101];
    bool visited[101][101]; fill(visited[0], visited[101], false);
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    cin >> N >> M;
    queue<pair<int, int>> q;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int num; cin >> num;
            box[i][j] = num;
            if (num == 1)
                q.push({ i,j });
        }
    }
    int count = 0;

    while(!q.empty()) {
        vector<pair<int, int>> tempXY;
        int num = q.size();
        for (int i = 0; i < num; i++) {
            int x = q.front().first; int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nextX = x + dx[k]; int nextY = y + dy[k];
                if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
                if (box[nextX][nextY] == 0 && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    box[nextX][nextY] = 1;
                    tempXY.push_back({ nextX,nextY });
                }
            }
        }
        for (int i = 0; i < tempXY.size(); i++) {
            q.push({ tempXY[i].first,tempXY[i].second });
        }
        count++;
    }
    count--;
    if (!check(box))
        count = -1;
    cout << count;
}