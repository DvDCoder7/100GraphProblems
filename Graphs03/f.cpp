#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void dfs(int v, vector<set<int>>& adj, vi& vis) {
    if(vis[v]) return;
    vis[v] = 1;
    for(auto u:adj[v]) dfs(u, adj, vis);
    return;
}

void solve() {
    int n; cin >> n;
    vector<set<int>> adj(n+26);
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < sz(str); j++) {
            int c = (str[j]-'a');
            c += n;
            adj[i].insert(c);
            adj[c].insert(i);
        }
    }
    vi vis(n+26, 0);
    int cont = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cont++;
            dfs(i, adj, vis);
        }
    }
    cout << cont << endl;
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