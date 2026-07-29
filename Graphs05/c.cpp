#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define vvi vector<vi>
#define vp vector<pii>
#define vvp vector<vp>
#define pii pair<int, int>
#define pb push_back

void solve() {
    int n; cin >> n;
    vvi adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    vi v(n+1, 0), pos(n+1);
    set <int> s;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        s.insert(v[i]);
        pos[v[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        sort(all(adj[i]), [&](int a, int b) {
            return (pos[a] < pos[b]);
        });
    }
    vi vis(n+1, 0);

    queue <int> q;
    vi r(1, 0);
    vis[1] = 1;
    q.push(1);
    while(!q.empty()) {
        auto x = q.front(); q.pop();
        r.pb(x);
        for(auto y:adj[x]) {
            if(vis[y] == 1) continue;
            vis[y] = 1;
            q.push(y);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(r[i] != v[i]) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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