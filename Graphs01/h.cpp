#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void solve() {
    int n; cin >> n;
    vector <vector<int>> v(n, vector<int>(n));
    vector <vector<int>> valido(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char a; cin >> a;
            v[i][j] = a - '0';
        }
    }

    bool temRes = true;
    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(v[i][j] == 0) continue;
            if(i == n-1 || j == n-1) valido[i][j] = 1;
            else {
                if(valido[i+1][j] || valido[i][j+1]) valido[i][j] = 1;
                else temRes = false;
            }
        }
    }

    if(temRes) cout << "YES\n";
    else cout << "NO\n";

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