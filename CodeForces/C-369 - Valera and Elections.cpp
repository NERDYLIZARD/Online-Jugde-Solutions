// 16th SEPT 2016
//codeforces.com/contest/369/problem/C
// dfs: O(N)

#include <iostream>
#include <vector>

using namespace std;

vector<pair<long, long>> t[100008];
vector<long> ans;

bool dfs(long n, long p, bool isProblem) {

    bool isNotified = 0;
    for (auto i : t[n]) {
        if (i.first == p) continue;
        isNotified |= dfs(i.first, n, i.second == 2);
    }

    if (!isNotified) {
        if (isProblem) {
            ans.push_back(n);
            return 1;
        } else
            return 0;
    }
    // notified - always report problem toward the top
    return 1;
}

int main() {
    long n; cin >> n;
    long x, y, k;
    for (int i = 1; i <= n-1 ; ++i) {
        cin >> x >> y >> k;
        t[x].push_back(make_pair(y, k));
        t[y].push_back(make_pair(x, k));
    }

    dfs(1, 0, 0);

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }

}




