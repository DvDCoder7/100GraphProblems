#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e5+10)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

void solve() {
    int n; cin >> n;
    vi v(n);
    vector<vi> dp(n, vi(2, MAXN));
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(n == 1) {
        cout << v[0] << endl;
        return;
    }
    dp[0][0] = v[0];
    dp[1][0] = v[0] + v[1];
    dp[1][1] = v[0];
    for(int i = 2; i < n; i++) {
        dp[i][0] = min(dp[i-1][1] + v[i], dp[i-2][1] + v[i-1] + v[i]);
        dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << endl;

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