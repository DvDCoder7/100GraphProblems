#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

string numeros[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int dist(string a, string target) {
    int cont = 0;
    for(int i = 0; i < 7; i++) {
        if(a[i] == '1' && target[i] == '0') return 10;
        if(a[i] == '0' && target[i] == '1') cont++;
    }
    return cont;
}

void solve() {
    int n, k; cin >> n >> k;
    string str[n];
    vi v(n+1, 0);
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    for(int i = 0; i <= 9; i++) {
        int d = dist(str[n-1], numeros[i]);
        if(d == 10 || d > k) continue;
        dp[n-1][d] = i;
    }
    
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j <= 9; j++) {
            int d = dist(str[i], numeros[j]);
            if(d == 10) continue;
            for(int x = 0; x <= k; x++) {
                if(d+x > k) continue;
                if(dp[i+1][x] == -1) continue;
                dp[i][d+x] = j;
            }
        }
    }
    if(dp[0][k] == -1) {
        cout << -1 << endl;
        return;
    }

    vi res;
    for(int i = 0; i < n; i++) {
        int r = dp[i][k];
        res.pb(r);
        k -= dist(str[i], numeros[r]);
    }

    for(auto p:res) cout << p;
    cout << endl;
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