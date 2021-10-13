#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> answer;
    int N; cin >> N;
    vector<int> target;
    for (int i = 0; i < N; i++) {
        int num = 0; cin >> num;
        target.push_back(num);
    }
    sort(target.begin(), target.end());
    int M; cin >> M;
    vector<int> arr;
    for (int i = 0; i < M; i++) {
        int num = 0; cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < M; i++) {
        int num = arr[i];
        int start = 0, end = N-1;
        int result = 0;

        if (num < target[start] || num > target[end]) {
            answer.push_back(result);
            continue;
        }

        while (start <= end) {
            int mid = (start + end) / 2;

            if (target[mid] == num) {
                result = 1;
                break;
            }
            else if (target[mid] > num) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        answer.push_back(result);
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}