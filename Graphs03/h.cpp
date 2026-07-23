#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void dfs(int v, vector <vi> &adj, vi &vis) {
    if(vis[v]) return;
    vis[v] = 1;
    for(auto u:adj[v]) dfs(u, adj, vis);
}

void solve() {
    int n, m; cin >> n >> m;

    vector <vi> adj(n+1);
    vi vis(n+1, 0);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int cont = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) cont++;
        dfs(i, adj, vis);
    }

    cout << m - (n-cont) << endl;

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