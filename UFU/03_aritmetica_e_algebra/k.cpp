#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int q; cin >> q;
    int d, ans=0;
    while(q--){
        cin >> d;
        if (d > 3) ans += d-3;
    }
    cout << ans << endl;

    return 0;
}