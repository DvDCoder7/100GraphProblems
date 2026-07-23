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
    int n; cin >> n;
    int mdist[n+1][n+1];
    char mat[n+1][n+1];
    
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> mat[i][j];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mat[i][j] == '0') mdist[i][j] = INT_MAX;
            else mdist[i][j] = 1;

            if(i == j) mdist[i][j] = 0;
        }
    }

    // floyd warshall
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(mdist[i][k] != INT_MAX && mdist[k][j] != INT_MAX) mdist[i][j] = min(mdist[i][k] + mdist[k][j], mdist[i][j]);
            }
        }
    }
    
    int m; cin >> m;
    vi path(m);
    for(int i = 0; i < m; i++) cin >> path[i];
    int ult = 0;
    vi res;
    res.pb(path[ult]);
    for(int i = 1; i < m; i++) {
        int v = path[ult], u = path[i];
        if(mdist[v][u] < i - ult) {
            ult = i-1;
            res.pb(path[ult]);
        }
    }
    res.pb(path[m-1]);
    cout << sz(res) << endl;
    for(auto p:res) cout << p << ' ';
    cout << endl;
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