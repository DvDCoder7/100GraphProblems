// Difficuldade: Muito Fácil ⭐️

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            if(j <= (n-1)/2) cout << 1 << ' ';
            else if(j*2 == n) cout << 0 << ' ';
            else cout << -1 << ' ';
        }
    }
    cout << endl;
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