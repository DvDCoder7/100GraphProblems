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
    vector <vi> adj(8);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int mn = m;
    for(int i = 1; i <= 7; i++) {
        for(int j = i+1; j <= 7; j++) {
            set <int> s;
            int cont = 0;
            for(auto u:adj[i]) {
                // if(u == j) cont++; // nao precisa tirar, pode deixar no set
                s.insert(u);
            }
            for(auto u:adj[j]) {
                s.insert(u);
            }
            cont = sz(adj[i]) + sz(adj[j]) - sz(s);
            mn = min(cont, mn);
        }
    }

    cout << m - mn << endl;
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