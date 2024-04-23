#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll P = 1e9+7;

ll expBin(ll a,ll b, ll M){
    if (b == 0) return 1;
    if (b&1) return (a*expBin(a, b-1, M))%M;
    ll x = expBin(a, b>>1, M)%M;
    return (x*x)%M;
}

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, a, b, c;
    cin >> n;
    while (n--){
        cin >> a >> b >> c;
        cout << expBin(a, expBin(b, c, P-1), P) << '\n';
    }
}