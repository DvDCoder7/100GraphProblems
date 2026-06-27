#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN ((int) 2*1e6)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

bool maior(int a[5], int b[5]) {
    int cont;
    cont = (a[0] < b[0]) + (a[1] < b[1]) + (a[2] < b[2]) + (a[3] < b[3]) + (a[4] < b[4]);
    return (cont >= 3);
}

void solve() {
    int n; cin >> n;
    int arr[n+1][5];
    int mx[5] = {0, 0, 0, 0, 0};
    int id = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 5; j++) cin >> arr[i][j];
        if(maior(arr[i], arr[id])) id = i;
    }

    bool tem = true;
    for(int i = 1; i <= n; i++) {
        if(i != id && !maior(arr[id], arr[i])) tem = false;
    }
    if(tem) cout << id << endl;
    else cout << -1 << endl;
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