#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    int n;
    ll m, p, b;
    cin >> n >> m;
    ll num[n];
    vector<ll> v[n+1];

    // create pow of 2 table for looking up
        // so that no need to compute 2^i, just num[i]
    num[0] = 1;
    for (int i = 1; i <= n; ++i) {
        num[i] = 2 * num[i-1];
    }

    ll temp;
    for (int i = 0; i < num[n]; ++i) {
        cin >> temp;
        v[n].push_back(temp);
    }

    bool toggle = true;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < num[i]; j++) {
            if (toggle)
                v[i].push_back(v[i+1][j*2] | v[i+1][j*2+1]);
            else
                v[i].push_back(v[i+1][j*2] ^ v[i+1][j*2+1]);
        }
        toggle = !toggle;
    }

    while(m--) {
        cin >> p >> b;
        --p;
        v[n][p] = b;

        toggle = true;
        for (int i = n-1; i >= 0; --i) {
            p /= 2;
            if (toggle)
                v[i][p] = v[i+1][p*2] | v[i+1][p*2+1];
            else
                v[i][p] = v[i+1][p*2] ^ v[i+1][p*2+1];

            toggle = !toggle;
        }
        cout << v[0][0] << '\n';
    }

}


