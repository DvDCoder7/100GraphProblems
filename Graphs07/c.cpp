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
    vector <vector<char>> mat(n+1, vector<char>(m+1));
    int sx, sy, tx, ty;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'S') sy = i, sx = j;
            if(mat[i][j] == 'T') ty = i, tx = j;
        }
    }
    vector<pii> v;
    vector<vi> dist(n+1, vi(m+1, 0));

    for(int i = sx; i < m; i++) {
        if(mat[sy][i] == '*') break;
        dist[sy][i] = 1;
    }
    for(int i = sx; i >= 0; i--) {
        if(mat[sy][i] == '*') break;
        dist[sy][i] = 1;
    }
    for(int i = sy; i < n; i++) {
        if(mat[i][sx] == '*') break;
        dist[i][sx] = 1;
    }
    for(int i = sy; i >= 0; i--) {
        if(mat[i][sx] == '*') break;
        dist[i][sx] = 1;
    }

    for(int i = tx; i < m; i++) {
        if(mat[ty][i] == '*') break;
        v.pb({ty, i});
    }
    for(int i = tx; i >= 0; i--) {
        if(mat[ty][i] == '*') break;
        v.pb({ty, i});
    }
    for(int i = ty; i < n; i++) {
        if(mat[i][tx] == '*') break;
        v.pb({i, tx});
    }
    for(int i = ty; i >= 0; i--) {
        if(mat[i][tx] == '*') break;
        v.pb({i, tx});
    }

    bool temRes = false;
    for(auto [y, x]:v) {
        for(int i = x; i < m; i++) {
            if(mat[y][i] == '*') break;
            if(dist[y][i] == 1) temRes = true;
        }
        for(int i = x; i >= 0; i--) {
            if(mat[y][i] == '*') break;
            if(dist[y][i] == 1) temRes = true;
        }
        for(int i = y; i < n; i++) {
            if(mat[i][x] == '*') break;
            if(dist[i][x] == 1) temRes = true;
        }
        for(int i = y; i >= 0; i--) {
            if(mat[i][x] == '*') break;
            if(dist[i][x] == 1) temRes = true;
        }
    }

    if(temRes) cout << "YES" << endl;
    else cout << "NO" << endl;
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