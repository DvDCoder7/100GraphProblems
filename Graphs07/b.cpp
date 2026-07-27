#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void dfs(int v, int dist, vector<vector<pii>> &adj, vi &mdist) {
    if(mdist[v] != -1) return;
    mdist[v] = dist;
    for(auto [u, d]:adj[v]) dfs(u, dist+d, adj, mdist);
    return;
}

void solve() {
    int n; cin >> n;
    vector <vector<pii>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    vi mdist(n+1, -1);
    dfs(0, 0, adj, mdist);
    int mx = 0;
    for(int i = 0; i < n; i++) {
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