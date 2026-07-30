#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define vvi vector<vi>
#define vp vector<pii>
#define vvp vector<vp>
#define pii pair<int, int>
#define pb push_back
#define MOD ((int)1e9 +7)

ll dfs(int v, vvi &adj, vi &vis) {
    if(vis[v]) return 0LL;
    vis[v] = 1;
    // if(sz(adj[v]) == 1) return 1LL;
    ll r = 1;
    for(auto u:adj[v]) {
        r += dfs(u, adj, vis);
    }
    return r;
}

void solve() {
    int n, k; cin >> n >> k;
    vvi adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(c == 0) {
            adj[a].pb(b); adj[b].pb(a);
        }
    }

    ll cont = 1;
    for(int i = 0; i < k; i++) {
        cont *= n; cont %= MOD;
    }
    vi vis(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        ll r = dfs(i, adj, vis);
        ll a = 1;
        for(int i = 0; i < k; i++) {
            a *= r; a %= MOD;
        }
        cont -= a;
        cont %= MOD;
    }

    cout << ((cont%MOD)+MOD)%MOD << endl;
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