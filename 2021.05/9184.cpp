#include <iostream>
#include <vector>
#include<string>
using namespace std;

int d[51][51][51];

int w(int a, int b, int c) {

    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (d[a][b][c] != 0) return d[a][b][c];
    if (a > 20 || b > 20 || c > 20) return d[20][20][20] = w(20,20,20);
    if (a < b && b < c) return d[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return d[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    while (true) {
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        v.push_back("w(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ") = " + to_string(w(a, b, c)));
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

}