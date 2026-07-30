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
    int n; cin >> n;
    vi ve(n+1), mdist(n+1, INT_MAX);

    vector<vi> adj(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> ve[i];
        adj[i].pb(ve[i]);
    }

    for(int i = 1; i < n; i++) {
        adj[i].pb(i+1);
        adj[i+1].pb(i);
    }

    queue <pii> q;
    q.push({0, 1});
    mdist[1] = 0;
    while(!q.empty()) {
        auto [d, v] = q.front(); q.pop();
        if(mdist[v] < d) continue;
        for(auto u:adj[v]) {
            if(mdist[u] <= d+1) continue;
            mdist[u] = d+1;
            q.push({d+1, u});
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << mdist[i] << ' ';
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