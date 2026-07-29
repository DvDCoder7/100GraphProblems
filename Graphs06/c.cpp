#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void dfs(int v, int d, vector <vi> &adj, vi &altura) {
    altura[v] = d;
    for(auto u:adj[v]) dfs(u, d+1, adj, altura);
}

void solve() {
    int n; cin >> n;
    vi pai(n+1);
    vector <vi> filhos(n+1);
    pai[1] = 1;
    for(int i = 2; i <= n; i++) {
        cin >> pai[i];
        filhos[pai[i]].pb(i);
    }
    vi altura(n+1, -1);
    dfs(1, 0, filhos, altura);
    map <int, int> freq;
    for(int i = 1; i <= n; i++) {
        freq[altura[i]] = freq[altura[i]]+1;
    }

    int res = 0;
    for(auto [k, v]:freq) {
        // cout << k << ' ' << v << endl;
        res += (v%2);
    }
    cout << res << endl;

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