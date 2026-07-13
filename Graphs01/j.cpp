#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void solve() {
    int a, b; cin >> a >> b;
    string c, d; cin >> c >> d;
    if(c[0] == '>' && d[0] == '^' && c[a-1] == '<' && d[b-1] == 'v') cout << "YES" << endl;
    else if(c[0] == '<' && d[0] == 'v' && c[a-1] == '>' && d[b-1] == '^') cout << "YES" << endl;
    else cout << "NO" << endl;
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