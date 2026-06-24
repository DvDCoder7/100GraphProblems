#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    ll res = 0;
    ll s = 0;
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    for(ll i = 0; i < n; i++) {
        res -= v[i]*i - s;
        s += v[i];
    }
    res += v[sz(v)-1]-v[0];

    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}