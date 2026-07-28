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

void dfs(int atual, int val, vvi &adj, vi &v, vi &vis) {
    if(vis[atual] != -1) return;
    vis[atual] = val*v[atual] + v[atual];
    for(auto u:adj[atual]) dfs(u, vis[atual], adj, v, vis);
    return;
}

void dfs2(int atual, int mx, vvi &adj, vi &v, vi &vis) {
    if(vis[atual] != -1) return;
    mx = max(mx, v[atual]);
    vis[atual] = mx;
    for(auto u:adj[atual]) dfs2(u, mx, adj, v, vis);
    return;
}

void solve() {
    int n, k; cin >> n >> k;
    vi v(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vvi adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    vi vis(n+1, -1), r(n+1, -1);
    dfs(1, 0, adj, v, vis);
    dfs2(1, 0, adj, vis, r);
    int cont = 0;
    for(int i = 2; i <= n; i++) {
        if(sz(adj[i]) == 1 && r[i] <= k) cont++;
    }
    cout << cont << endl;
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