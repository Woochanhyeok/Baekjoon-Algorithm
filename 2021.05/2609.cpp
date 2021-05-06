#include <iostream>

using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    int greatest, least;
    for (int i = min(a, b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            greatest = i;
            break;
        }
    }
    for (int i = max(a,b); ; i++) {
        if (i % a == 0 && i % b == 0) {
            least = i;
            break;
        }
    }
    cout << greatest << "\n" << least;
}