#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define vi vector<int>
#define MAX 212345
#define endl '\n'

void solve(){
    int n, m, k; 
    cin >> n >> m >> k;
    vi a(k+1), b(k+1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x <= k) a[x] = 1;
    }
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        if (x <= k) b[x] = 1;
    }


    int qtdA = 0;
    int qtdB = 0;

    for (int i = 1; i <= k; i++){
        if (a[i] && !b[i]) qtdA++;
        else if (!a[i] && b[i]) qtdB++;
        else if (!a[i] && !b[i]) {cout << "NO" << endl; return;}
    }
    if (qtdA > k/2 || qtdB > k/2) {cout << "NO" << endl; return;}
   
    cout << "YES" << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}