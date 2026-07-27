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
    vi aponta(26);
    int n; cin >> n;
    vector<string> res;
    for(int i = 0; i < 26; i++) {
        aponta[i] = i;
    }
    string s1, s2; cin >> s1 >> s2;
    for(int i = 0; i < n; i++) {
        int a = s1[i]-'a';
        int b = s2[i]-'a';
        
        // dá p fazer um DSU, mas achei essa forma mais facil
        a = aponta[a]; b = aponta[b];
        if(a == b) continue;

        aponta[a] = min(aponta[a], aponta[b]);
        aponta[b] = min(aponta[a], aponta[b]);

        res.pb(string(1, s1[i]) + " " + s2[i]);
        for(int j = 0; j < 26; j++) {
            aponta[j] = aponta[aponta[j]];
        }
    }
    cout << res.size() << endl;
    for(auto p:res) cout << p << endl;
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