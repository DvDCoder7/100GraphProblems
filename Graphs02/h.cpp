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
    int n; cin >> n;
    string str; cin >> str;
    int cont = 0;
    bool dir = false, esq = false;
    for(int i = 0; i < n; i++) {
        if(str[i] == '<') esq = true;
        if(str[i] == '>') dir = true;
        if(str[i] == '-') {
            cont++;
            if(str[(i+1)%n] != '-') cont++;
        }
    }

    if(!dir || !esq) cout << n << endl;
    else cout << cont << endl;

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