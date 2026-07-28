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
    vi freq(n+10);
    set <pii> s;
    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        freq[a]++;
        s.insert({a, a});

        if(a == 1) {
            if(freq[2] > 0) s.insert({2, 1});
        } else if(a == n) {
            if(freq[n-1] > 0) s.insert({n-1, n});
        } else {
            if(freq[a+1] > 0) s.insert({a+1, a});
            if(freq[a-1] > 0) s.insert({a-1, a});
        }
    }
    // for(auto [a, b]:s) cout << a << ' ' << b << endl;
    cout << 3*n - 2 - sz(s) << endl;
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