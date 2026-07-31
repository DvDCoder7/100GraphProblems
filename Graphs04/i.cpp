#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define MOD (998244353)

bool dfs(int v, int c, int aux, vector <vi> &adj, vi &cores) {
    if(cores[v] != -1) {
        if(cores[v] == aux + c) return true;
        return false;
    }
    cores[v] = aux + c;
    bool pode = true;
    for(auto u:adj[v]) {
        pode = (pode && dfs(u, (c+1)%2, aux, adj, cores));
    }
    return pode;
}

void solve() {
    int n, m; cin >> n >> m;
    vector <vi> adj(n+1);
    vi cores(n+1, -1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    
    bool temRes = true;
    int comp = 0;
    for(int i = 1; i <= n; i++) {
        if(cores[i] == -1) {
            temRes = (temRes && dfs(i, 0, comp, adj, cores));
            comp+=2;
        }
    }
    
    if(!temRes) cout << 0 << endl;
    else {
        vi freq(comp+1, 0);
        for(int i = 1; i <= n; i++) {
            freq[cores[i]]++;
        }
        ll res = 1LL;
        for(int i = 0; i < comp; i += 2) {
            ll a = 1, b = 1;
            for(int j = 0; j < freq[i]; j++) {
                a *= 2; a %= MOD;
            }
            for(int j = 0; j < freq[i+1]; j++) {
                b *= 2; b %= MOD;
            }
            res *= (a+b) %MOD;
            res %= MOD;
        }
        cout << res << endl;
    }

    return;
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