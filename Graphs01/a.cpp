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
    int primeiro = n+2;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        if(a == 1) primeiro = min(i, primeiro);
    }
    if(primeiro != n+2) {
        for(int i = 1; i < primeiro; i++) {
            cout << i << ' ';
        }
        cout << n+1 << ' ';
        for(int i = primeiro; i <= n; i++) {
            cout << i << ' ';
        }
        cout << endl;
    } else {
        for(int i = 1; i <= n+1; i++) {
            cout << i << ' ';
        }
        cout << endl;
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