#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void solve() {
    int n, m; cin >> n >> m;
    vi contMaior(n+1, 0);
    int res = 0;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        int mn = min(u, v);
        contMaior[mn]++;
        if(contMaior[mn] == 1) res++;
    }

    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int u, v; cin >> u >> v;
            int mn = min(u, v);
            contMaior[mn]++;
            if(contMaior[mn] == 1) res++;
        } else if(op == 2) {
            int u, v; cin >> u >> v;
            int mn = min(u, v);
            contMaior[mn]--;
            if(contMaior[mn] == 0) res--;
        } else {
            cout << n-res << endl;
        }
    }
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