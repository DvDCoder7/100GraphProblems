#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

int cont;
void dfs(int n, int m, vector<vector<char>> &mat, vector<vi> &vis) {
    if(vis[n][m] || mat[n][m] == '#') return;
    vis[n][m] = 1;
    if(mat[n][m] == 'G') cont--;
    if(mat[n][m] == 'B') cont = INT_MAX;
    dfs(n+1, m, mat, vis);
    dfs(n, m+1, mat, vis);
    dfs(n-1, m, mat, vis);
    dfs(n, m-1, mat, vis);
    
}


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> mat(n+2, vector<char>(m+2, '#'));
    vector<vector<int>> vis(n+2, vector<int>(m+2, 0));
    cont = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'G') cont++;
        }
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mat[i][j] == 'B') {
                if(mat[i+1][j] == '.') mat[i+1][j] = '#';
                if(mat[i][j+1] == '.') mat[i][j+1] = '#';
                if(mat[i-1][j] == '.') mat[i-1][j] = '#';
                if(mat[i][j-1] == '.') mat[i][j-1] = '#';
            }
        }
    }

    dfs(n, m, mat, vis);
    if(cont == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

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