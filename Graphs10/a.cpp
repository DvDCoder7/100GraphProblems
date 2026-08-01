// Tem solucao mais facil usando S - a, S - b, S - c

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
    int a, b, c;
    cin >> a >> b >> c;
    int q = (a+b+c)/2;
    if((a+b+c)%2 == 1) cout << "Impossible" <<  endl;
    else {
        int ab = 0, bc = 0, ca = 0;
        if(b > c) {
            int d = b-c;
            ab += d;
            a -= d;
            b -= d;
        } else {
            int d = c-b;
            ca += d;
            a -= d;
            c -= d;
        }
        
        if(a >= 0) {
            if( ab + a/2 < 0 || (b+c)/2 - a/2 < 0 || ca + a/2 < 0) cout << "Impossible" << endl;
            else cout << ab + a/2 << ' '  << (b+c)/2 - a/2 << ' ' << ca + a/2 << endl;
        } else cout << "Impossible" << endl;
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
