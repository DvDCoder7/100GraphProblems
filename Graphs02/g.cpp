#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

bool ordenado(vi &v) {
    for(int i = 0; i < sz(v); i++) {
        if(i+1 != v[i]) return false; 
    }
    return true;
}

void op1(vi &v) {
    int n = sz(v)/2;
    for(int i = 0; i < 2*n; i+=2) {
        swap(v[i], v[i+1]);
    }
}

void op2(vi &v) {
    int n = sz(v)/2;
    for(int i = 0; i < n; i++) {
        swap(v[i], v[i+n]);
    }
}

void solve() {
    int n; cin >> n;
    vi v(2*n), v1(2*n);
    for(int i = 0; i < 2*n; i++) {
        cin >> v[i];
        v1[i] = v[i];
    }
    int primeiro = v[0];
    ll t1 = 0, t2 = 0;

    while(!ordenado(v)) {
        t1++;
        op1(v);
        if(ordenado(v)) {
            break;
        }
        if(v[0] == primeiro) {
            t1 = LLONG_MAX;
            break;
        }
        t1++;
        op2(v);
        if(ordenado(v)) {
            break;
        }
        if(v[0] == primeiro) {
            t1 = LLONG_MAX;
            break;
        }
    }

    while(!ordenado(v1)) {
        t2++;
        op2(v1);
        if(ordenado(v1)) {
            break;
        }
        if(v1[0] == primeiro) {
            t2 = LLONG_MAX;
            break;
        }
        t2++;
        op1(v1);
        if(ordenado(v1)) {
            break;
        }
        if(v1[0] == primeiro) {
            t2 = LLONG_MAX;
            break;
        }
    }

    if(min(t1, t2) != LLONG_MAX) cout << min(t1, t2) << endl;
    else cout << -1 << endl;
    

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