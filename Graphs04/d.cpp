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
    int n;
    cin >> n;
    cout << 1 << ' ' << n-1 << ' ';
    for(int i = 1; i <= n; i++) {
        cout << i << ' ';
    }
    cout << endl;
    int mx; cin >> mx;
    int l = 2, r = n;

    while(l < r) {
        int m = (l+r)/2;
        int s = m-l+1;
        cout << 1 << ' ' << s << ' ';
        cout << 1 << ' ';
        for(int i = l; i <= m; i++) {
            cout << i << ' ';
        }
        cout << endl;
        int d; cin >> d;

        if(d == mx) r = m;
        else l = m+1;
    }

    cout << 1 << ' ' << n-1 << ' ' << l << ' ';
    for(int i = 1; i <= n; i++) {
        if(i != l) cout << i << ' ';
    }
    cout << endl;

    int res; cin >> res;
    cout << -1 << ' ' << res << endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}