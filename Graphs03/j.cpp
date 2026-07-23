#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void dfs(int v, int cor, vector<vi> &adj, vi &vis) {
    if(vis[v]) return;
    vis[v] = cor;
    for(auto u:adj[v]) dfs(u, (cor%2)+1, adj, vis);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vi> adj1(n+1);
    vi vis1(n+1, 0);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj1[a].pb(b); adj1[b].pb(a);
    }

    vector <vi> adj(n+1);
    queue <int> q;
    q.push(1);
    vis1[1] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto u:adj1[v]) {
            if(vis1[u]) continue;
            vis1[u] = 1;
            q.push(u);
            adj[v].pb(u); adj[u].pb(v);
        }
    }
    vi vis(n+1);
    dfs(1, 1, adj, vis);
    vi r1, r2;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 1) r1.pb(i);
        else r2.pb(i);
    }
    
    if(sz(r1) < sz(r2)) {
        cout << sz(r1) << endl;
        for(auto p:r1) cout << p << ' ';
    } else {
        cout << sz(r2) << endl;
        for(auto p:r2) cout << p << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}