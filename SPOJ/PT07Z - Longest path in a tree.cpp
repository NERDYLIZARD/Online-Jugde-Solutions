#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#define whatIs(x) std::cerr << #x << ": " << x << std::endl;

using namespace std;

map<int, vector<int>> mapp;
bool check[10001] = {false};
int findDiameter(int);
int total;


int main() {
    int n;
    cin >> n;
    int x, y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        mapp[x].push_back(y);
        mapp[y].push_back(x);
    }

    findDiameter(1);
    cout << total << endl;

    return 0;
}

int findDiameter(int n) {
    check[n] = 1;
    int mx = -1, secMx = -1;
    for (auto it : mapp[n]) {
        if (!check[it]) {
            int temp = findDiameter(it);
            if (mx <= temp) {
                secMx = mx;
                mx = temp;
            }
            else if (secMx < temp) {
                secMx = temp;
            }
        }
    }
    total = max(total, mx + secMx + 2);
    return mx + 1;

}

