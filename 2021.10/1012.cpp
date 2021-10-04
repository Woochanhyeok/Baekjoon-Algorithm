#include <iostream>
#include <vector>
using namespace std;



bool visited[50][50];
int ground[50][50];
int M, N, K;

void dfs(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) return;
    if (!visited[x][y] && ground[x][y] == 1) {
        visited[x][y] = true;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }
}

int main()
{
    int T; cin >> T;
    vector <int> result;

    for (int i = 0; i < T; i++) {
        int answer = 0;
        fill(visited[0], visited[50], false);
        fill(ground[0], ground[50], 0);
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++) {
            int x, y; cin >> x >> y;
            ground[x][y] = 1;
        }
        for (int k = 0; k < M; k++) {
            for (int l = 0; l < N; l++) {
                if (!visited[k][l] && ground[k][l] == 1) {
                    dfs(k, l);
                    answer++;
                }
            }
        }
        result.push_back(answer);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
}