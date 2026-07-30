#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

bool dfs(int v, int c, vector <vi> &adj, vi &cores) {
    if(cores[v] != -1) {
        if(cores[v] == c) return true;
        return false;
    }
    cores[v] = c;
    bool pode = true;
    for(auto u:adj[v]) {
        pode = (pode && dfs(u, (c+1)%2, adj, cores));
    }
    return pode;
}

void solve() {
    int n, m; cin >> n >> m;
    vector <vi> adj(n+1);
    vi cores(n+1, -1);
    vector <pii> e;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        e.pb({a, b});
    }

    if(dfs(1, 0, adj, cores)) {
        cout << "YES" << endl;
        for(auto [a, b]:e) {
            if(cores[a] == 1) cout << 1;
            else cout << 0; 
        }
        cout << endl;
    } else cout << "NO" << endl;


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