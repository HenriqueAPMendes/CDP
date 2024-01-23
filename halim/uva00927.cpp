#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll expbin(ll a, ll b){
    if (b == 0) return 1;
    if (b & 1) return a*expbin(a,b-1);
    ll x = expbin(a,b>>1);
    return x*x;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll c, degree, d, k;
    cin >> c;

    while(c--){
        cin >> degree;
        vector<ll> c(degree+1);
        for (int i = 0; i <= degree; i++) cin >> c[i];
        cin >> d;
        cin >> k;

        ll ans = 0;
        ll elements_covered = 0;
        int n, j;
        for (n = 1; n < k; n++){ // n loop
            elements_covered += n*d;
            // cout <<"covered: " << elements_covered << " n=" << n << endl;
            if (elements_covered >= k) break;
        }
        for (j = 0; j <= degree; j++) {// exponent loop
            ans += c[j]*expbin(n,j);
            // cout << c[j] << ' ' << ans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}