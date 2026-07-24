#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void dfs(int v, int dist, vector<vi> &adj, vi &mdist) {
    if(mdist[v] != -1) return;
    mdist[v] = dist;
    for(auto u:adj[v]) dfs(u, dist+1, adj, mdist);
}

void solve() {
    int n, m; cin >> n;
    int a, b; cin >> b;
    m = n-1, a = 1;
    vector <vi> adj(n+1);
    vi mdista(n+1, -1), mdistb(n+1, -1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(a, 0, adj, mdista); dfs(b, 0, adj, mdistb);
    int mx = 0;
    int mn = n+1;
    for(int i = 1; i < n+1; i++) {
        if(mdista[i] > mdistb[i]) mx = max(mdista[i], mx);
        if(mdista[i] == mdistb[i]) mn = min(mdista[i], mn);
    }
    if(mn == n+1) cout << mx*2 << endl;
    else cout << max(mx, mn)*2 << endl;
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