#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define vi vector<int>

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n+1);
    for (int i = 1; i <= n; i++) a[i] = i;

    int l = 1, r = n;
    // verificacoes NO
    if (k & 1) { cout << "NO" << endl; return; }
    if (n & 1 == 0 && k > 2*n){ cout << "NO" << endl; return; }
    if (n & 1 && k > (1+n)*n/2){ cout << "NO" << endl; return; }
    cout << "YES" << endl;
    

    while(k != 0){
        int diff = (r-l)*2;
        if (k >= diff){
            k -= diff;
            swap(a[l], a[r]);
            l++; r--;
        }
        else r--;
        if (l >= r) break; 
    }

    if (k != 0) { cout << "NO" << endl; return; }

    for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
}

signed main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}