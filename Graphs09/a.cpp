#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define tii tuple<int, int, int>
#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> mat(n+1, vi(n+1, 0));

    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    
    vector<vi> adj0(n+1), adj1(n+1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mat[i][j] == 1) adj1[i].pb(j);
            else adj0[i].pb(j);
        }
    }
    
    vi mdist0(n+1, INT_MAX);
    queue <pii> pq0;
    mdist0[n] = 0;
    pq0.push({0, n});
    while(!pq0.empty()) {
        auto [d, v] = pq0.front(); pq0.pop();
        if(mdist0[v] < d) continue;
        for(auto nv:adj0[v]) {
            if(mdist0[nv] <= d+1) continue;
            mdist0[nv] = d+1;
            pq0.push({d+1, nv});
        }
    }   
    vi mdist1(n+1, INT_MAX);
    queue <pii> pq1;
    mdist1[n] = 0;
    pq1.push({0, n});
    while(!pq1.empty()) {
        auto [d, v] = pq1.front(); pq1.pop();
        if(mdist1[v] < d) continue;
        for(auto nv:adj1[v]) {
            if(mdist1[nv] <= d+1) continue;
            mdist1[nv] = d+1;
            pq1.push({d+1, nv});
        }
    }

    int mn = INT_MAX;
    if(mat[1][n] == 1) mn = mdist0[1];
    if(mat[1][n] == 0) mn = mdist1[1];
    if(mn == INT_MAX) cout << -1 << endl;
    else cout << mn << endl;
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