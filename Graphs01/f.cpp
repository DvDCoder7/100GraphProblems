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
    int pais = 0;
    int filhos = 1;
    int alt = 0;
    int ult;
    cin >> ult;
    ult = n+2;
    for(int i = 1; i < n; i++) {
        int a; cin >> a;
        // cout << i << ": ";
        if(a > ult) {
            // cout << 1 << endl;
            filhos++;
            ult = a;
        } else {
            if(pais > 0) {
            // cout << 2 << endl;
                pais--;
                ult = a;
                filhos++;
            } else {
            // cout << 3 << endl;
                pais = filhos-1;
                ult = a;
                filhos = 1;
                alt++;
            }
        }
    }

    cout << alt << endl;
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