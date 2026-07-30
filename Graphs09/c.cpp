#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    vector <vi> adj(n+1, vi(n+1, 0));
    vi deg(n+1, 0);
    vector <pii> pares;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
        pares.pb({a, b});
        deg[a]++; deg[b]++;
    }
    int mn = INT_MAX;
    for(auto [a, b]:pares) {
        for(int c = 1; c <= n; c++) {
            if(adj[a][c] && adj[b][c]) mn = min(deg[a] + deg[b] + deg[c] - 6, mn); 
        }
    }
    if(mn != INT_MAX) cout << mn << endl;
    else cout << -1 << endl;
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