#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define MOD ((int)1e9 +7)
void solve() {
    int n; cin >> n;
    vi a(n), b(n), vis(n+1, 0);
    vi vaiPara(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vaiPara[a[i]] = x;
    }
    int cont = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        int atual = vaiPara[i];
        while(atual != i) {
            vis[atual] = 1;
            atual = vaiPara[atual];
        }

        cont++;
    }
    ll res = 1;
    for(int i = 0; i < cont; i++) {
        res *= 2;
        res %= MOD;
    }
    cout << res << endl;
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