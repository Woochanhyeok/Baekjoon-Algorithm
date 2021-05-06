#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T; cin >> T;
    vector<int> result;
    
    for (int i = 0; i < T; i++) {
        int a, b; cin >> a >> b;
        int num1 = a, num2 = b;
        int c = 0;
        c = max(a, b);
        a = min(a, b);
        b = c;
        while (true) {
            int r = b % a;
            if (r == 0) {
                result.push_back(num1*num2/a);
                break;
            }
            else {
                b = a;
                a = r;
            }
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
}