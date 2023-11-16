#include <bits/stdc++.h>
using namespace std;

int P = 1e9+7;
typedef long long ll;

ll expBin(ll a,ll b){
    if (b == 0) return 1;
    if (b&1) return (a*expBin(a, b-1))%P;
    ll x = expBin(a, b>>1);
    return (x*x)%P;
}

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a, b;
    cin >> n;
    while (n--){
        cin >> a >> b;
        cout << expBin(a, b) << '\n';
    }
}