#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findMax(vector<int> v, int num) {
    int leftMax = 0, rightMax = 0;
    for (int i = 0; i < num; i++) {
        if (v[i] > leftMax)
            leftMax = v[i];
    }
    for (int i = num + 1; i < v.size(); i++) {
        if (v[i] > rightMax)
            rightMax = v[i];
    }
    if (num == 0) leftMax = v[num];
    if (num == v.size() - 1) rightMax = v[num];

    return { leftMax,rightMax };
}

int main()
{
    int H, W; cin >> H >> W;
    vector<int> blocks;
    int answer = 0;
    for (int i = 0; i < W; i++) {
        int num; cin >> num;
        blocks.push_back(num);
    }

    for (int i = 0; i < blocks.size(); i++) {
        pair<int, int> lrMax = findMax(blocks, i);
        if (lrMax.first == 0 && lrMax.second == 0) {
            answer = 0;
            break;
        }
        if(min(lrMax.first,lrMax.second)-blocks[i] >= 0)
            answer += min(lrMax.first, lrMax.second) - blocks[i];
    }
    cout << answer;
}