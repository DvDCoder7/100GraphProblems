#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define MOD ((int)1e9 + 7)
void solve() {
    int n; cin >> n;
    ll fat = 1;
    ll pot = 1;
    for(int i = 1; i <= n; i++) {
        fat *= i;
        fat %= MOD;
    }
    for(int i = 1; i < n; i++) {
        pot *= 2;
        pot %= MOD;
    }
    // cout << fat << ' ' << pot << endl;
    cout << ((fat - pot)%MOD + MOD)%MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}