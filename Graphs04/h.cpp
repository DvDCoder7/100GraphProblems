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

void solve() {
    int n, m; cin >> n >> m;
    vvi adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    priority_queue <int, vi, greater<>> q;
    vi vis(n+1, 0);
    q.push(1);
    vis[1] = 1;
    while(!q.empty()) {
        int v = q.top(); q.pop();
        cout << v << ' ';
        for(auto u:adj[v]) {
            if(vis[u]) continue;
            vis[u] = 1;
            q.push(u);
        }
    }
    cout << endl;

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