#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

int calc(int v, vi &subtree, vector <vi> &filhos) {
    int r = 0;
    for(auto u:filhos[v]) r += calc(u, subtree, filhos);
    return subtree[v] = max(r, 1);
}

void solve() {
    int n; cin >> n;
    vi pai(n+1);
    vector <vi> filhos(n+1);
    vi subtree(n+1, 0);
    pai[1] = 1;
    for(int i = 2; i <= n; i++) {
        cin >> pai[i];
        filhos[pai[i]].pb(i);
    }

    calc(1, subtree, filhos);
    vi freq(n+1, 0);
    for(int i = 1; i <= n; i++) {
        freq[subtree[i]]++;
    }
    int r = 0, qtd = 0;
    for(int i = 1; i <= n; i++) {
        while(qtd < i) {
            r++;
            qtd += freq[r];
        }
        cout << r << ' ';
    }
    cout << endl;
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