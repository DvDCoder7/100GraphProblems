#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void dfs(int v, int comp, vector<vi> &adj, vi &vis) {
    if(vis[v] != 0) return;
    vis[v] = comp;
    for(auto u:adj[v]) dfs(u, comp, adj, vis);
}

void solve() {
    int n, m; cin >> n >> m;
    vector <vi> adj(n+1);
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        int v = -1;
        for(int j = 0; j < k; j++) {
            int u; cin >> u;
            if(v == -1) v = u;
            else {
                adj[u].pb(v); adj[v].pb(u);
                v = u;
            }
        }
    }

    int comp = 1;
    vi vis(n+1, 0);
    for(int i = 1; i <= n; i++) {
        if(vis[i] != 0) continue;
        dfs(i, comp, adj, vis);
        comp++;
    }

    vi freq(comp+1, 0);
    for(int i = 1; i <= n; i++) {
        freq[vis[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        cout << freq[vis[i]] << ' ';
    }
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