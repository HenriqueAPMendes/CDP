#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define vi vector<int>

void solve(){
    int n, f, k;
    cin >> n >> f >> k;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    f = a[f-1];
    sort(a.rbegin(), a.rend());

    if (a[k-1] < f) cout << "YES" << endl;
    else if (a[k-1] > f) cout << "NO" << endl;
    else { // a[k-1] == f
        if(k < n && a[k] == f) cout << "MAYBE" << endl;
        else cout << "YES" << endl;
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}