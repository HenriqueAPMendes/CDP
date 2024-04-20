#include <bits/stdc++.h>
using namespace std;

#define int long long int 
#define endl '\n'
#define vi vector<int>

void solve(){
    int n, k;
    cin >> n >> k;
    cout << n << ' ' << k << endl;
    /**
     * first iteration - 2k + 1
     * second iteration - 4k + 2
     * i-th iteration => 2^i(k) + 2^(i-1)
     * 
     * 2k + 1 == n
     * ceil((n-1)/2)
     * i-th =>
     * ceil((n-(1<<(i-1)))/(1<<i))
    */

    // find iteration
    int it = 1, qtd = 0;
    bool foundK = false;
    int thisIteration = 0;
    while(true){
        thisIteration = (n-(1<<(it-1)))/(1<<it);
        if (n&1) thisIteration++;
        cout << thisIteration << ' ';
        qtd += thisIteration;
        if (qtd == k){
            foundK = true; break;
        }
        else if (qtd < k) it++;
        else if (qtd > k) break;
    }
    cout << endl;
    if (foundK){
        int ans = (1<<it)*(thisIteration-1) + 1<<(it-1);
        cout << ans << endl;
    }
    else{
        int index = k - (qtd-thisIteration);
        int ans = (1<<it)*(index-1) + 1<<(it-1);
        cout << ans << endl;    
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}