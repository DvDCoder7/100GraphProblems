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
    ll n, m;
    cin >> n >> m;
    ll maiorComp = 1;
    for(int i = 1; i <= n; i++) {
        maiorComp = i;
        if(maiorComp*(maiorComp-1)/2 >= m) break;
    }
    if(maiorComp == 1) maiorComp = 0;
    cout << max(n-m*2, 0LL) << ' ' << n - maiorComp << endl;
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