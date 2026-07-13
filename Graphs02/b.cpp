#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int find(int x, vi &pai) {
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x], pai);
}

void join(int x, int y, vi &nivel, vi &pai) {
    x = find(x, pai), y = find(y, pai);
    if(x == y) return;
    if(nivel[x] < nivel[y]) swap(x, y);
    pai[y] = x;
    if(nivel[x] == nivel[y]) nivel[x]++;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vi pai1(n+1), pai2(n+1);
    vi nivel1(n+1, 0), nivel2(n+1, 0);
    for(int i = 0; i <= n; i++) {
        pai1[i] = pai2[i] = i;
    }
    for(int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        join(u, v, nivel1, pai1);
    }
    for(int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        join(u, v, nivel2, pai2);
    }

    vector<pair<int, int>> res;
    for(int u = 1; u <= n; u++) {
        for(int v = 1; v <= n; v++) {
            if(find(u, pai1) != find(v, pai1)) {
                if(find(u, pai2) != find(v, pai2)) {
                    join(u, v, nivel1, pai1);
                    join(u, v, nivel2, pai2);
                    res.pb({u, v});
                }
            }
        }
    }

    cout << res.size() << endl;
    for(auto [u, v]:res) cout << u << ' ' << v << endl;
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