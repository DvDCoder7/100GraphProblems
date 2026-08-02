// Note that the contrains says that m < n/2. This means that at least one city can build a road to all other cities, otherwise m >= n/2.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define vvi vector<vi>
#define vp vector<pii>
#define vvp vector<vp>
#define pii pair<int, int>
#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    vi freq(n+1, 0);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        freq[a]++;
        freq[b]++;
    }

    int usar = 0;
    for(int i = 1; i <= n; i++) {
        if(freq[i] == 0) usar = i;
    }
    cout << n-1 << endl;
    for(int i = 1; i <= n; i++) {
        if(i == usar) continue;
        cout << i << ' ' << usar << endl;
    }
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