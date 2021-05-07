#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int X; cin >> X;

    int DP[1000001] = {0,};

    for (int i = 2; i <= X; i++) {
        DP[i] = DP[i - 1] + 1;

        if (i % 3 == 0) {
            DP[i] = min(DP[i], DP[i / 3] + 1);
        }
        if (i % 2 == 0) {
            DP[i] = min(DP[i], DP[i / 2] + 1);
        }
    }
    cout << DP[X];
    
}