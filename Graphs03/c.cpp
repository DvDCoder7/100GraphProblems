#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    vector <vi> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector <pii> v;
    vi id(n+1);
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        id[i] = a;
        v.pb({a, i});
    }
    sort(all(v));
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        map <int, int> mex;
        for(auto p:adj[i]) mex[id[p]] = 1;
        int aux = id[i]+1;
        for(int j = 1; j <= aux; j++) {
            if(mex[j] == 0) aux = j;
        }
        if(aux != id[i]) ok = false;
    }

    if(ok) {
        for(auto [a, b]:v) cout << b << ' ';
    } else cout << -1;

    cout << endl;
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