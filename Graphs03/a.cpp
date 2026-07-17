#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

pii centroid(int v, int p, vector<vi> &adj, vi &subtree) {
    
    for(auto u:adj[v]) {
        if(u == p) continue;
        if(2*subtree[u] >= subtree[1]) {
            if(2*subtree[u] == subtree[1]) return {u, v};
            return centroid(u, v, adj, subtree);
        }
    }

    return {v, -1};
}

int subtreesz(int v, int p, vector<vi> &adj, vi &subtree) {
    int r = 1;
    for(auto u:adj[v]) {
        if(u == p) continue;
        r += subtreesz(u, v, adj, subtree);
    }
    return subtree[v] = r;
}

int encontraFolha(int v, int p, vector<vi> &adj) {
    if(sz(adj[v]) == 1) return v;

    for(auto u:adj[v]) {
        if(u == p) continue;
        return encontraFolha(u, v, adj);
    }

    return -1;
}

void solve() {
    int n; cin >> n;
    vector <vi> adj(n+1);
    vi subtree(n+1, 1);

    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }
    subtreesz(1, 1, adj, subtree);
    pii c = centroid(1, 1, adj, subtree);
    if(c.second == -1) {
        cout << 1 << ' ' << adj[1][0] << endl;
        cout << 1 << ' ' << adj[1][0] << endl;
        return;
    }
    int folha = encontraFolha(c.first, c.second, adj);
    cout << adj[folha][0] << ' ' << folha << endl;
    cout << folha << ' ' << c.second << endl;
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