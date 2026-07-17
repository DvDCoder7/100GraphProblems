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
    int cont = 0;
    vi adj(n+1, -1);
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        adj[x] = y;
    }

    for(int i = 1; i <= n; i++) {
        if(adj[i] == i || adj[i] == -1) continue;
        cont++;
        int atual = adj[i];
        adj[i] = -1;
        while(atual != -1) {
            if(atual == i) {
                cont++;
                break;
            }
            if(adj[atual] == -1) break;
            int aux = adj[atual];
            adj[atual] = -1;
            atual = aux;
            cont++;
        }
    }

    cout << cont << endl;
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