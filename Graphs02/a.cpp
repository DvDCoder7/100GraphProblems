#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void solve() {
    int n, m;
    cin >> n >> m;
    vi adj[n+1];
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int qtd1 = 0, qtd2 = 0;
    for(int i = 1; i<= n; i++) {
        if(adj[i].size() == 1) qtd1++;
        if(adj[i].size() == 2) qtd2++;
    }
    if(qtd1 == 2 && qtd2 == n-2) cout << "bus topology" << endl;
    else if(qtd1 == 0 && qtd2 == n) cout << "ring topology" << endl;
    else if(qtd1 == n-1) cout << "star topology" << endl;
    else cout << "unknown topology" << endl;
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