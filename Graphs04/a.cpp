#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

bool c(int x, int y, vector<pii> v) {
    for(auto [a, b]:v) {
        if(a != x && a != y && b != x && b != y) return false;
    }
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    vector <pii> v;

    int x, y; cin >> x >> y;
    v.pb({x, y});
    for(int i = 1; i < m; i++) {
        int a, b; cin >> a >> b;
        v.pb({a, b});
    }
    int z = -1, w = -1;
    for(auto [a, b]:v) {
        if(a != x && a != y && b != x && b != y) {
            z = a, w = b;
        }
    }

    if(z == -1) cout << "YES" << endl;
    else {
        if(c(x, z, v) || c(x, w, v) || c(y, z, v) || c(y, w, v)) cout << "YES\n";
        else cout << "NO\n";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}