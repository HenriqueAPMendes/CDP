#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;

vector<vector<ll>> fator;

vector<ll> final(38,0), 
            primes = {2,3,5,7,11,13,17,19,23,29,31,37};

vector<ll> fatora (int n){
    vector<ll> fatores(38, 0);
    for (int x=2; x*x<= n; x++)
    while(n%x == 0){
        fatores[x]++;;
        n/=x;
    }
    if (n>1) fatores[n]++;
    return fatores;
}

long long expBin(ll a, ll b){
    if (b == 0) return 1;
    if (b % 2) return a * expBin(a,b-1);
    ll x = expBin(a, b/2);
    return x*x;
}

ll maxE(ll p){
    ll ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, fator[i][p]);
    return ans;
}

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    fator = vector<vector<ll>>(N, vector<ll>(38,0));
    
    for (ll i = N+1; i <= 2*N; i++)
        fator[i-N-1] = fatora(i);

    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < 12; j++) 
    //         cout << fator[i][j] << ' ';
    //     cout << endl;
    // }    

    for (ll i = 0; i < 38; i++)
        final[i] = maxE(i);
    
    ll ans = 1;

    for (int i = 0; i < 12; i++)
        ans *= expBin(primes[i], final[primes[i]]);
    
    cout << ans << endl;

    return 0;
}