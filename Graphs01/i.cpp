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
    vi usado(n+1, 0);
    int meninaNaoUsada = -1;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        bool achou = false;
        for(int j = 0; j < k; j++) {
            int a; cin >> a;
            if(achou) continue;
            if(usado[a] == true) continue;
            usado[a] = true;
            achou = true;
        }
        if(!achou) meninaNaoUsada = i+1;
    }

    if(meninaNaoUsada == -1) {
        cout << "OPTIMAL" << endl;
    } else {
        int meninoNaoUsado = -1;
        for(int i = 1; i <= n; i++) if(!usado[i]) meninoNaoUsado = i;
        cout << "IMPROVE" << endl;
        cout << meninaNaoUsada << ' ' << meninoNaoUsado << endl;
    }

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