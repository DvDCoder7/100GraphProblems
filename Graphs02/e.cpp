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
    vi v(n+1, -1);
    vi usado(n+1, 0);
    vi b(n+1);
    int qtd = 0;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        b[i] = a;
        if(usado[a]) {
            qtd++;
            continue;
        }
        usado[a] = i;
        v[i] = a;
    }
    cout << n - qtd << endl;
    queue <int> semPresente;
    for(int i = 1; i <= n; i++) if(usado[i] == 0) semPresente.push(i);
    for(int i = 1; i <= n; i++) {
        if(v[i] != -1) continue;
        if(i != semPresente.front()) {
            v[i] = semPresente.front();
            usado[semPresente.front()] = i;
            semPresente.pop();

        } else {
            v[usado[b[i]]] = semPresente.front();
            usado[semPresente.front()] = usado[b[i]];
            v[i] = b[i];
            usado[b[i]] = i;
            semPresente.pop();
        }
    }

    for(int i = 1; i <= n; i++) cout << v[i] << ' ';
    cout << endl;
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