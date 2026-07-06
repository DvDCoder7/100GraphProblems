#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    vi ca(a+1), cb(b+1);
    vector <pii> pares(k);
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        pares[i].first = x;
        ca[x]++;
    }
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        pares[i].second = x;
        cb[x]++;
    }
    ll cont = 0;
    for(auto [i, j]:pares) {
        cont += (k - ca[i] - cb[j]) +1;
    }
    cout << cont/2 << endl;
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