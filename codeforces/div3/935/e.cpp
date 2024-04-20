#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

void solve(){
    int n, x;
    cin >> n >> x;
    vi p(n), used(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    int l = 0, r = n;
    int mid;
    cout << "search: ";
    while(r-l > 1){
        mid = (l+r)>>1;
        used[mid] = 1;
        // cout << mid << ' ';
        if (p[mid] <= x) l = mid;
        else r = mid;
    }
    // cout << endl;
    if (p[mid] == x) cout << 0 << endl;
    else{
        int u;
        for (int i = 0; i < n; i++) 
            if (!used[i] && p[i] != x)
                u = i;
        cout << u << endl;
        int xindex;
        for (int i = 0; i < n; i++)
            if (p[i] == x)
                xindex = i;
        cout << 1 << endl << x << ' ' << u << endl;
        
    }
    
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}