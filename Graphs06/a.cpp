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
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vi> mat(n+1, vi(n+1, 0));
    vector <vi> adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
        mat[a][b] = 1; mat[b][a] = 1;
    }

    vi mdists(n+1, INT_MAX), mdistt(n+1, INT_MAX);
    priority_queue <pii, vector<pii>, greater<>> pq;
    pq.push({0, s});
    mdists[s] = 0;
    while(!pq.empty()) {
        auto [dist, v] = pq.top(); pq.pop();
        if(mdists[v] < dist) continue;
        for(auto u:adj[v]) {
            int d = 1;
            if(mdists[u] <= dist+d) continue;
            mdists[u] = dist+d;
            pq.push({dist+d, u});
        }
    }

    pq.push({0, t});
    mdistt[t] = 0;
    while(!pq.empty()) {
        auto [dist, v] = pq.top(); pq.pop();
        if(mdistt[v] < dist) continue;
        for(auto u:adj[v]) {
            int d = 1;
            if(mdistt[u] <= dist+d) continue;
            mdistt[u] = dist+d;
            pq.push({dist+d, u});
        }
    }

    int cont = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(mat[i][j] == 0) if(mdists[i] + mdistt[j] + 1 >= mdistt[s] && mdists[j] + mdistt[i] + 1 >= mdistt[s]) cont++;
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