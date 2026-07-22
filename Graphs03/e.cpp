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
    vector<vi> adj(n+1);
    vector<vi> radj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a); // direcao contraria
    }
    int q; cin >> q;
    vi caminho(q);
    for(int i = 0; i < q; i++) cin >> caminho[i];

    priority_queue<pii, vector<pii>, greater<>> pq;
    vi mdist(n+1, INT_MAX);
    pq.push({0, caminho[q-1]});
    mdist[caminho[q-1]] = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if(mdist[v] < d) continue;
        for(auto u:radj[v]) {
            if(d+1 >= mdist[u]) continue;
            mdist[u] = d+1;
            pq.push({d+1, u});
        }
    }
    
    int mn = 0, mx = 0;
    for(int i = 0; i < sz(caminho)-1; i++) {
        int aux = mdist[caminho[i+1]];
        bool temIgual = false, temMenor = false;

        for(auto u:adj[caminho[i]]) {
            if(u == caminho[i+1]) continue;
            if(mdist[u] == aux) temIgual = true;
            if(mdist[u] < aux) temMenor = true;
        }

        if(temMenor) mn = mn+1, mx = mx+1;
        else if(temIgual) mx++;
    }
    
    cout << mn << ' ' << mx << endl;
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