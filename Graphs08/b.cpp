/*
    The properties of the graph are:
    1. It should be possible to exchange thoughts between any two pairs of brains (perhaps indirectly, through other brains).
    2. There should be no redundant brain connectors, that is, removing any brain connector would make property 1 false. 
*/

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

void calc(int v, int d, vvi &adj, vi &mdist) {
    if(mdist[v] != -1) return;
    mdist[v] = d;
    for(auto u:adj[v]) calc(u, d+1, adj, mdist);
}

void solve() {
    int n, m; cin >> n >> m;
    vvi adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    vi mdist(n+1, -1);

    int v1 = 1;
    calc(1, 0, adj, mdist);
    for(int i = 1; i <= n; i++) {
        if(mdist[i] > mdist[v1]) v1 = i;
    }
    fill(all(mdist), -1);
    calc(v1, 0, adj, mdist);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(mdist[i], mx);
    }

    cout << mx << endl;
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