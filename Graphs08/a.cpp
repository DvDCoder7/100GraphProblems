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
    int n, m, k; cin >> n >> m >> k;
    vector <tuple<int, int, int>> v;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v.pb({a, b, c});
    }
    vi storage(n+1, 0);
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        storage[a] = 1;
    }
    int mn = INT_MAX;
    for(auto [a, b, c]:v) {
        if(storage[a] && !storage[b]) mn = min(c, mn);
        if(!storage[a] && storage[b]) mn = min(c, mn);
    }
    if(mn == INT_MAX) cout << -1 << endl;
    else cout << mn << endl;

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